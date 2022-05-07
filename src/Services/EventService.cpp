#include "EventService.h"
#include "StatusCode.h"

/* Private */

void EventService::updateSoonestUpcoming() {
	
}

unsigned EventService::indexOfEvent(const Date& date) {
	// TODO: make binary search
	for (unsigned i = indSoonestUpcoming; i < events.get_count(); i++) {
		if (events[i].get_date().compare(date) == 0)
			return i;
	}
	return events.get_count();
}

unsigned EventService::indexOfEvent(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(date);
	if (ind < events.get_count() && events[ind].get_name().compare(name) == 0)
		return ind;
	return events.get_count();
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

	unsigned eInd = events.findIndex(Event(hallNumber, "", date));
	if (eInd < events.get_count())
		return E_EventWillOverlap;

	events.insert(Event(*hall, name, date));
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
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	return events[ind].reserveTicket(ticket, password, note);
}

StatusCode EventService::cancelTicketReservation(const char* name, const Date& date, unsigned seatRow, unsigned seatColumn) {
	return cancelTicketReservation(name, date, Ticket(seatRow, seatColumn));
}

StatusCode EventService::cancelTicketReservation(const char* name, const Date& date, const Ticket& ticket) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;
	
	return events[ind].cancelReservation(ticket);
}

StatusCode EventService::buyTicket(const char* name, const Date& date, unsigned row, unsigned seat) {
	return buyTicket(name, date, Ticket(row, seat));
}

StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	return events[ind].buyTicket(ticket);
}

StatusCode EventService::buyTicket(const char* name, const Date& date, unsigned row, unsigned seat, const char* password) {
	return buyTicket(name, date, Ticket(row, seat), password);
}

StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	return events[ind].buyTicketFromReservation(Reservation(ticket), password);
}


const Hall* EventService::queryEventHall(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return nullptr;

	return &events[ind].get_hall();
}

OrderedList<Ticket> EventService::queryTickets(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return OrderedList<Ticket>();

	return events[ind].get_tickets();
}

OrderedList<Reservation> EventService::queryReservations(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return OrderedList<Reservation>();

	return events[ind].get_reservations();
}
