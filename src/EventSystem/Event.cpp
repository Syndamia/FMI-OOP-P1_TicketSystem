#include "Event.h"
#include "StatusCodes.h"

Event::Event() : Event(nullptr, "", DateTime()) {}

Event::Event(const Hall* hall, String name, DateTime time) {
	this->hall = hall;
	this->name = name;
	this->time = time;
}

StatusCode Event::reserveTicket(const Ticket& ticket, const char* password, const char* note) {
	if (tickets.contain(ticket)) return E_TicketAlreadyBought;
	if (reservations.contain(Reservation(ticket, "", ""))) return E_TicketAlreadyReserved;

	reservations.insert(Reservation(ticket, password, note));
	return Success;
}

StatusCode Event::cancelReservation(const Ticket& ticket) {

}
