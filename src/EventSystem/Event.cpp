#include "Event.h"
#include "StatusCodes.h"

Event::Event() : Event(nullptr, "", DateTime()) {}

Event::Event(const Hall* hall, String name, DateTime time) {
	this->hall = hall;
	this->name = name;
	this->time = time;
}

StatusCode Event::reserveTicket(const Ticket& ticket, const char* password, const char* note) {
	// TODO: if (reservations.contains(ticket) || tickets.contain(ticket)) return E_...
	reservations.insert(Reservation(ticket, password, note));
	return Success;
}

StatusCode Event::cancelReservation(const Ticket& ticket) {

}
