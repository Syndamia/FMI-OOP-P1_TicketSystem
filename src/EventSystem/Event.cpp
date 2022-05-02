#include "Event.h"
#include "Reservation.h"
#include "StatusCodes.h"

Event::Event() : Event(nullptr, "", DateTime()) {}

Event::Event(const Hall* hall, String name, DateTime time) {
	this->hall = hall;
	this->name = name;
	this->time = time;
}

StatusCode Event::reserveTicket(const Ticket& ticket, const char* password, const char* note) {
	if (tickets.contain(ticket)) return E_TicketAlreadyBought;
	if (reservations.contain(ticket)) return E_TicketAlreadyReserved;

	reservations.insert(Reservation(ticket, password, note));
	return Success;
}

StatusCode Event::cancelReservation(const Ticket& ticket) {
	unsigned ind = reservations.findIndex(ticket);
	if (ind == reservations.get_count())
		return W_TicketWasNotReserved;

	reservations.removeAt(ind);
	return Success;
}

StatusCode Event::buyTicket(const Ticket& ticket) {
	if (tickets.contain(ticket)) return E_TicketAlreadyBought;
	if (reservations.contain(ticket)) return E_TicketAlreadyReserved;

	tickets.insert(ticket);
	return Success;
}

StatusCode Event::buyTicketFromReservation(const Reservation& reservation, const char* password) {
	if (!reservations.contain(reservation)) return E_ReservationDoesNotExist;

	if (!reservation.checkPassword(password)) return E_WrongReservationPassword;

	reservations.removeAt
}
