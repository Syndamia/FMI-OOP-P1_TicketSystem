#include "Event.h"
#include "Reservation.h"

Event::Event() : hall(), name(), date() {}

Event::Event(const Hall& hall, String name, Date date) : tickets(), reservations() {
	this->hall = &hall;
	this->name = name;
	this->date = date;
}

const OrderedList<Ticket>& Event::get_tickets() const {
	return tickets;
}

const OrderedList<Reservation>& Event::get_reservations() const {
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

int Event::compare(const Event& other) {
	if (hall == other.hall)
		return date.compare(other.date);
	return hall->compare(*other.hall);
}
