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

void Event::read(std::istream& istr) {
	hall.read(istr);
	name.read(istr);
	date.read(istr);
	tickets.read(istr);
	reservations.read(istr);
}

void Event::write(std::ostream& ostr) {
	hall.write(ostr);
	name.write(ostr);
	date.write(ostr);
	tickets.write(ostr);
	reservations.write(ostr);
}

int Event::compare(const Event& other) {
	if (hall.compare(other.hall) == 0)
		return date.compare(other.date);
	return hall.compare(other.hall);
}

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

std::ostream& operator<<(std::ostream& ostr, const Event& event) {
	ostr << "Hall: " << event.get_hall() << " Name: " << event.get_name() << " Date: " << event.get_date() << std::endl;

	ostr << "Bought tickets: ";
	for (unsigned i = 0; i < event.get_tickets().get_count(); i++)
		ostr << event.get_tickets()[i] << " ";
	ostr << std::endl << "Reserved tickets: ";
	for (unsigned i = 0; i < event.get_reservations().get_count(); i++)
		ostr << event.get_reservations()[i] << " ";
	return ostr << std::endl;
}
