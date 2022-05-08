#include "EventService.h"
#include "StatusCode.h"
#include <cstring>
#include <fstream>

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

	Event newEv(hs->get_halls()[hInd], name, date);

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

StatusCode EventService::ticketIsReserved(const char* name, const Date& date, const Ticket& ticket) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	if (events[eInd].get_reservations().contain(ticket))
		return Success;
	else
		return W_TicketHadNotBeenReserved;
}

StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket) {
	return buyTicket(name, date, ticket, nullptr, nullptr);
}

StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password, String* reservationNoteOutput) {
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

		if (reservationNoteOutput != nullptr)
			*reservationNoteOutput = events[eInd].get_reservations()[rInd].get_note();
		events[eInd].get_reservations().removeAt(rInd);
	}

	events[eInd].get_tickets().insert(ticket);
	return Success;
}

String EventService::createSeatingString(const char* name, const Date& date, unsigned* seatsPerRow) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count()) {
		return "";
	}

	unsigned rowCount = events[eInd].get_hall().get_rows(), seatsCount = events[eInd].get_hall().get_seatsPerRow();
	*seatsPerRow = seatsCount;

	String out = new char[rowCount * seatsCount + 1];

	for (unsigned acc = 0, row = 1; row <= rowCount; row++) {
		for (unsigned seat = 1; seat <= seatsCount; seat++, acc++) {
			if (events[eInd].get_tickets().contain(Ticket(row, seat)))
				out[acc] = 'B';
			else if (events[eInd].get_reservations().contain(Ticket(row, seat)))
				out[acc] = 'R';
			else
				out[acc] = ' ';
		}
	}

	out[seatsCount * rowCount] = '\0';
	return out;
}

unsigned indexToInsertWhenTicketSort(const List<Event>& elem, unsigned topN, unsigned ticketCount) {
	for (unsigned i = 0; i < elem.get_count() && i < topN; i++) {
		if (elem[i].get_tickets().get_count() < ticketCount)
			return i;
	}
	return topN;
}

StatusCode EventService::queryMostWatched(unsigned topN) {
	List<Event> result;
	for (unsigned i = 0; i < events.get_count(); i++) {
		if (result.get_count() > 10 && result[10].get_tickets().get_count() > events[i].get_tickets().get_count())
			continue;

		
	}
}

template <typename T>
bool cond_event_all(const Event& e1, T scrap) {
	return true;
}

bool cond_event_name(const Event& e, const char* name) {
	return e.get_name().compare(name) == 0;
}

bool cond_event_date(const Event& e, const Date& date) {
	return e.get_date().compare(date) == 0;
}

StatusCode EventService::reportReservations(const char* name, const Date& date) {
	List<Event> result;
	bool (*cond_name)(const Event&, const char*) = cond_event_name;
	bool (*cond_date)(const Event&, const Date&) = cond_event_date;
	
	if (strcmp(name, "ALL") == 0) cond_name = cond_event_all;
	if (date.compare(Date(0, 0, 0)) == 0) cond_date = cond_event_all;

	for (unsigned i = 0; i < events.get_count(); i++) {
		if (cond_name(events[i], name) && cond_date(events[i], date))
			result.add(events[i]);
	}

	std::ofstream outFile("report.txt"); // TODO: filename
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	configureEventInsertionOp(0b101);
	outFile << result;
	outFile.close();

	return Success;
}

bool cond_event_hallNumber(const Event& event, int hallNumber) {
	return event.get_hall().get_number() == hallNumber;
}

bool cond_event_dates(const Event& event, const Date& start, const Date& end) {
	return event.get_date().compare(start) >= 0 && event.get_date().compare(end) <= 0;
}

StatusCode EventService::reportBoughtTickets(int hallNumber, const Date& start, const Date& end, bool all) {
	List<Event> result;
	bool (*cond_hall)(const Event&, int) = cond_event_hallNumber;
	if (all) cond_hall = cond_event_all;

	for (unsigned i = 0; i < events.get_count(); i++) {
		if (cond_hall(events[i], hallNumber) && cond_event_dates(events[i], start, end))
			result.add(events[i]);
	}

	std::ofstream outFile("boughtTickets.txt"); // TODO: filename
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	configureEventInsertionOp(0b01001);
	outFile << result;
	outFile.close();

	return Success;

}

StatusCode EventService::load() {
	std::ifstream inFile("eventsDatabase.fmits");
	if (!inFile.is_open())
		return E_FileCouldNotBeOpened;

	events.read(inFile);
	inFile.close();
	return Success;
}

StatusCode EventService::save() {
	std::ofstream outFile("eventsDatabase.fmits");
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	events.write(outFile);
	outFile.close();
	return Success;
}
