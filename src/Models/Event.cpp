#include "Event.h"
#include "Reservation.h"

Event::Event() : hall(), name(), date() {}

Event::Event(const Hall& hall, String name, Date date) : tickets(), reservations() {
	this->hall = hall;
	this->name = name;
	this->date = date;
}

OrderedList<Ticket>& Event::get_tickets() {
	return tickets;
}

const OrderedList<Ticket>& Event::get_tickets() const {
	return tickets;
}

OrderedList<Reservation>& Event::get_reservations() {
	return reservations;
}

const OrderedList<Reservation>& Event::get_reservations() const {
	return reservations;
}

const Hall& Event::get_hall() const {
	return hall;
}

const String& Event::get_name() const {
	return name;
}

const Date& Event::get_date() const {
	return date;
}

/*! \param istr An input stream
 *
 * Directly reads bytes from stream (calls read() function).
 * Stored types must have defined a read() function.
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ifstream
 */
void Event::read(std::istream& istr) {
	hall.read(istr);
	name.read(istr);
	date.read(istr);
	tickets.read(istr);
	reservations.read(istr);
}

/*! \param ostr An output stream
 *
 * Directly writes bytes to stream (calls write() function).
 * Stored types must have defined a read() function.
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ofstream
 */
void Event::write(std::ostream& ostr) {
	hall.write(ostr);
	name.write(ostr);
	date.write(ostr);
	tickets.write(ostr);
	reservations.write(ostr);
}

/*! \return compare of halls, or if they are equal, compare of dates
 */
int Event::compare(const Event& other) {
	if (hall.compare(other.hall) == 0)
		return date.compare(other.date);
	return hall.compare(other.hall);
}

/*!
 * Uses the stream's >> operator to read and parse all internal values.
 * Stored types must have defined operator >>.
 *
 * \note Best used with std::cin or text std::ifstream
 */
std::istream& operator>>(std::istream& istr, Event& event) {
	Hall newHall;
	String newString;
	Date newDate;
	OrderedList<Ticket> newTickets;
	OrderedList<Reservation> newReservation;

	istr >> newHall >> newString >> newDate >> newTickets >> newReservation;
	event = Event(newHall, newString, newDate);
	event.get_tickets() = newTickets;
	event.get_reservations() = newReservation;

	return istr;
}

unsigned insertionOpSet = 0;

/*! \param setting A number, defining the different options. It's best if it is passed as binary number.
 *
 * Sets a configuration setting for how operator<< should behave. Setting is stored as a global variable in the cpp file, so it's independent of Event instance.
 *
 * Each bit in the number is a certain setting. Each bit from left to right represents one of these options, from top to bottom:
 * 1. Write count of bought tickets (available only if 5. is set)
 * 2. Write count of reserved tickets (available only if 5. is set)
 * 3. Write reservations
 * 4. Write bought tickets
 * 5. Write Hall information
 *
 * \par Example
 * To configure printing the Hall information, bought tickets count and the bought tickets themselves, you would do:
 * \code{.cpp}
 * configureEventInsertionOp(0b10011);
 * \endcode
 */
void configureEventInsertionOp(unsigned setting) {
	insertionOpSet = setting;
}

/*!
 * Uses the stream's << operator to write all internal data, following setting from configureEventInsertionOp()
 * Stored types must have defined operator <<.
 *   
 * \note Best used with std::cout or text std::ofstream
 */
std::ostream& operator<<(std::ostream& ostr, const Event& event) {
	if (insertionOpSet & 1) {
		ostr << "| Hall: " << event.get_hall().get_number() << " | Name: " << event.get_name() << " | Date: " << event.get_date();

		if (insertionOpSet & 8)
			ostr << " || Tickets Count: " << event.get_tickets().get_count();
		if (insertionOpSet & 16)
			ostr << " || Reservations Count: " << event.get_reservations().get_count();
		ostr << std::endl;
	}
	if (insertionOpSet & 2) {
		ostr << "Bought tickets: ";
		for (unsigned i = 0; i < event.get_tickets().get_count(); i++)
			ostr << "[" << event.get_tickets()[i] << "] ";
		ostr << std::endl;
	}
	if(insertionOpSet & 4) {
		ostr << "Reserved tickets: ";
		for (unsigned i = 0; i < event.get_reservations().get_count(); i++)
			ostr << "[" << event.get_reservations()[i] << "] ";
		ostr << std::endl;
	}
	return ostr;
}
