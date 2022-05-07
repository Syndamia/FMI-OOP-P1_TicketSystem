#include "EventService.h"
#include "StatusCode.h"
#include <cstring>

/* Private */

void EventService::updateSoonestUpcoming() {
	
}

unsigned EventService::indexOfEvent(const char* name, const Date& date) {
	// TODO: binary search
	for (unsigned i = 0; i < events.get_count(); i++) {
		if (events[i].get_date().compare(date) == 0 && events[i].get_name().compare(name) == 0)
			return i;
	}
	return events.get_count();
}

bool correctReservationPassword(const Reservation& res, const char* password) {
	return strcmp(res.get_password(), password) == 0;
}

/* Public */

EventService::EventService(const HallService* hs) {
	this->hs = hs;
	events = OrderedList<Event>();
	indSoonestUpcoming = 0;
}

EventService::EventService(const HallService* hs, const Event* events, unsigned eventCount) {
	this->hs = hs;
	this->events = OrderedList<Event>(events, eventCount);
	indSoonestUpcoming = 0;
	updateSoonestUpcoming();
}

StatusCode EventService::createEvent(int hallNumber, const String& name, const Date& date) {
	unsigned hInd = hs->get_halls().findIndex(Hall(hallNumber));
	if (hInd == hs->get_halls().get_count())
		return E_HallDoesntExist;

	Event newEv(hallNumber, name, date);

	unsigned eInd = events.findIndex(newEv);
	if (eInd < events.get_count())
		return E_EventWillOverlap;

	events.insert(newEv);
	return Success;
}

StatusCode EventService::cancelEvent(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	events.removeAt(ind);
	return Success;
}

StatusCode EventService::reserveTicket(const char* name, const Date& date, const char* password, const char* note, unsigned seatRow, unsigned seatColumn) {
	return reserveTicket(name, date, password, note, Ticket(seatRow, seatColumn));
}

StatusCode EventService::reserveTicket(const char* name, const Date& date, const char* password, const char* note, const Ticket& ticket) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	unsigned tInd = events[eInd].get_tickets().findIndex(ticket);
	if (tInd < events[eInd].get_tickets().get_count())
		return E_TicketAlreadyBought;

	Reservation res(ticket, password, note);

	unsigned rInd = events[eInd].get_reservations().findIndex(res);
	if (rInd < events[eInd].get_reservations().get_count())
		return E_TicketAlreadyReserved;

	events[eInd].get_reservations().insert(res);
	return Success;
}

StatusCode EventService::cancelTicketReservation(const char* name, const Date& date, unsigned seatRow, unsigned seatColumn) {
	return cancelTicketReservation(name, date, Ticket(seatRow, seatColumn));
}

StatusCode EventService::cancelTicketReservation(const char* name, const Date& date, const Ticket& ticket) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	unsigned rInd = events[eInd].get_reservations().findIndex(ticket);
	if (rInd == events[eInd].get_reservations().get_count())
		return W_TicketHadNotBeenReserved;

	events[eInd].get_reservations().removeAt(rInd);
	return Success;
}

StatusCode EventService::buyTicket(const char* name, const Date& date, unsigned row, unsigned seat) {
	return buyTicket(name, date, Ticket(row, seat), nullptr);
}

StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket) {
	return buyTicket(name, date, ticket, nullptr);
}

StatusCode EventService::buyTicket(const char* name, const Date& date, unsigned row, unsigned seat, const char* password) {
	return buyTicket(name, date, Ticket(row, seat), password);
}

StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	unsigned tInd = events[eInd].get_tickets().findIndex(ticket);
	if (tInd < events[eInd].get_tickets().get_count())
		return E_TicketAlreadyBought;

	unsigned rInd = events[eInd].get_reservations().findIndex(ticket);
	if (rInd < events[eInd].get_reservations().get_count()) {
		if (password == nullptr)
			return E_TicketAlreadyReserved;
		if (!correctReservationPassword(events[eInd].get_reservations()[rInd], password))
			return E_WrongReservationPassword;

		events[eInd].get_reservations().removeAt(rInd);
	}

	events[eInd].get_tickets().insert(ticket);
	return Success;
}

String EventService::createSeatingString(const char*name, const Date& date) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return "";

	unsigned strSize = events[eInd].get_hall().get_rows() * events[eInd].get_hall().get_seatsPerRow();
	String out;
}
