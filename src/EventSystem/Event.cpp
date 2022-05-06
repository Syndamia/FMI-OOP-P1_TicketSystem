#include "Event.h"
#include "Reservation.h"
#include "StatusCodes.h"

Event::Event() : Event(nullptr, "", Date()) {}

Event::Event(const Hall* hall, String name, Date date) : tickets(), reservations() {
	this->hall = hall;
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

StatusCode Event::reserveTicket(const Ticket& ticket, const char* password, const char* note) {
	if (tickets.contain(ticket)) return E_TicketAlreadyBought;
	if (reservations.contain(ticket)) return E_TicketAlreadyReserved;

	reservations.insert(Reservation(ticket, password, note));
	return Success;
}

StatusCode Event::cancelReservation(unsigned row, unsigned seat) {
	return cancelReservation(Ticket(row, seat));
}

StatusCode Event::cancelReservation(const Ticket& ticket) {
	unsigned ind = reservations.findIndex(ticket);
	if (ind == reservations.get_count())
		return W_TicketHadNotBeenReserved;

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
	unsigned resInd = reservations.findIndex(reservation);
	if (resInd == reservations.get_count()) return E_ReservationDoesNotExist;

	if (!reservations[resInd].validPassword(password)) return E_WrongReservationPassword;

	reservations.removeAt(resInd);
	tickets.insert(reservation.get_ticket());
	return Success;
}

int Event::compare(const Event& other) {
	// TODO: improve
	return name.compare(other.name);
}
