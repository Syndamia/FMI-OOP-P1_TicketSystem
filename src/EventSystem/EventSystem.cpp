#include "EventSystem.h"
#include "StatusCodes.h"

/* Private */

void EventSystem::updateSoonestUpcoming() {
	
}

unsigned EventSystem::indexOfEvent(const Date& date) {
	// TODO: make binary search
	for (unsigned i = indSoonestUpcoming; i < events.get_count(); i++) {
		if (events[i].get_date().compare(date) == 0)
			return i;
	}
	return events.get_count();
}

unsigned EventSystem::indexOfEvent(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(date);
	if (ind < events.get_count() && events[ind].get_name().compare(name) == 0)
		return ind;
	return events.get_count();
}

/* Public */

EventSystem::EventSystem() {
	events = OrderedList<Event>();
	indSoonestUpcoming = 0;
}

EventSystem::EventSystem(const Event* events, unsigned eventCount) {
	this->events = OrderedList<Event>(events, eventCount);
	indSoonestUpcoming = 0;
	updateSoonestUpcoming();
}

StatusCode EventSystem::createEvent(const Hall* hall, String name, Date date) {
	if (indexOfEvent(date) < events.get_count())
		return E_EventWillOverlap;

	events.insert(Event(hall, name, date));
	return Success;
}

StatusCode EventSystem::cancelEvent(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	events.removeAt(ind);
	return Success;
}

StatusCode EventSystem::reserveTicket(const char* name, const Date& date, const char* password, const char* note, unsigned seatRow, unsigned seatColumn) {
	return reserveTicket(name, date, password, note, Ticket(seatRow, seatColumn));
}

StatusCode EventSystem::reserveTicket(const char* name, const Date& date, const char* password, const char* note, const Ticket& ticket) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	return events[ind].reserveTicket(ticket, password, note);
}

StatusCode EventSystem::cancelTicketReservation(const char* name, const Date& date, unsigned seatRow, unsigned seatColumn) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;
	
	return events[ind].cancelReservation(seatRow, seatColumn);
}

StatusCode EventSystem::buyTicket(const char* name, const Date& date, unsigned row, unsigned seat) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	return events[ind].buyTicket(Ticket(row, seat));
}


StatusCode EventSystem::buyTicket(const char* name, const Date& date, unsigned row, unsigned seat, const char* password) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	return events[ind].buyTicketFromReservation(Reservation(Ticket(row, seat)), password);
}

List<Ticket> EventSystem::queryFreeTickets(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(name, date);

	if (ind == events.get_count())
		return List<Ticket>();

	List<Ticket> freeTickets;

	unsigned nextIndT = 0, nextIndR = 0;
	for (unsigned r = 1; r <= events[ind].get_hall().get_rowCount(); r++) {
		for (unsigned s = 1; s <= events[ind].get_hall().get_seatsPerRow(); s++) {
			// TODO: finish
		}
	}

	return freeTickets;
}
