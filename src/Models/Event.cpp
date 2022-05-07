#include "Event.h"
#include "Reservation.h"

Event::Event() : hall(), name(), date() {}

Event::Event(const Hall& hall, String name, Date date) : tickets(), reservations() {
	this->hall = &hall;
	this->name = name;
	this->date = date;
}

OrderedList<Ticket>& Event::get_tickets() {
	return tickets;
}

OrderedList<Reservation>& Event::get_reservations() {
	return reservations;
}

const Hall& Event::get_hall() const {
	return *hall;
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
	if (hall == other.hall)
		return date.compare(other.date);
	return hall->compare(*other.hall);
}

std::istream& operator>>(std::istream& istr, Event& event) {
	return istr >> event.hall >> event.name >> event.date >> event.tickets >> event.reservations;
}
std::ostream& operator<<(std::ostream& ostr, const Event& event) {
	ostr << "Hall: " << event.hall << " Name: " << event.name << " Date: " << event.date << std::endl;

	ostr << "Bought tickets: ";
	for (unsigned i = 0; i < event.tickets.get_count(); i++)
		ostr << event.tickets[i] << " ";
	ostr << std::endl << "Reserved tickets: ";
	for (unsigned i = 0; i < event.reservations.get_count(); i++)
		ostr << event.reservations[i] << " ";
	return ostr << std::endl;
}
