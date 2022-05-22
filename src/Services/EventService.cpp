#include "EventService.h"
#include "StatusCode.h"
#include <cstring>
#include <fstream>

/* Private */

unsigned EventService::indexOfEvent(const char* name, const Date& date) {
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
}

EventService::EventService(const HallService* hs, const Event* events, unsigned eventCount) {
	this->hs = hs;
	this->events = OrderedList<Event>(events, eventCount);
}

/*!
 * Uses HallService pointer to get Hall from hallNumber
 * \return E_HallDoesntExist \b if hallNumber doesn't correspond to any Hall, saved in HallService
 * \return E_EventWillOverlap \b if Event's date overlaps with another event in the same Hall
 * \return Success \b otherwise
 */
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

/*!
 * \return E_EventDoesNotExist \b if No Event with the given name and date exists
 * \return Success \b otherwise
 */
StatusCode EventService::cancelEvent(const char* name, const Date& date) {
	unsigned ind = indexOfEvent(name, date);
	if (ind == events.get_count())
		return E_EventDoesNotExist;

	events.removeAt(ind);
	return Success;
}

/*!
 * \return E_EventDoesNotExist \b if No Event with the given name and date exists
 * \return E_TicketAlreadyBought \b if A ticket for the given row and seat has already been bought
 * \return E_TicketAlreadyReserved \b if A reservation has already been placed on the given row and seat
 * \return Success \b otherwise
 */
StatusCode EventService::reserveTicket(const char* name, const Date& date, const char* password, const char* note, const Ticket& ticket) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	if (events[eInd].get_hall().get_rows() < ticket.get_row() || events[eInd].get_hall().get_seatsPerRow() < ticket.get_seat())
		return E_InvalidSeat;

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

/*!
 * Canceling a reservation doesn't require password and doesn't return the Reservation's note
 *
 * \return E_EventDoesNotExist \b if No Event with the given name and date exists
 * \return W_TicketHadNotBeenReserved \b Ticket hadn't been reserved in the first place
 * \return Success \b otherwise
 */
StatusCode EventService::cancelTicketReservation(const char* name, const Date& date, const Ticket& ticket) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	if (events[eInd].get_hall().get_rows() < ticket.get_row() || events[eInd].get_hall().get_seatsPerRow() < ticket.get_seat())
		return E_InvalidSeat;

	unsigned rInd = events[eInd].get_reservations().findIndex(ticket);
	if (rInd == events[eInd].get_reservations().get_count())
		return W_TicketHadNotBeenReserved;

	events[eInd].get_reservations().removeAt(rInd);
	return Success;
}

/*!
 * \return E_EventDoesNotExist \b if No Event with the given name and date exists
 * \return W_TicketHadNotBeenReserved \b Ticket hadn't been reserved in the first place
 * \return Success \b otherwise
 */
StatusCode EventService::ticketIsReserved(const char* name, const Date& date, const Ticket& ticket) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	if (events[eInd].get_reservations().contain(ticket))
		return Success;
	else
		return W_TicketHadNotBeenReserved;
}

/*!
 * Calls buyTicket with Reservation, but sets password and noteOutput to nullptr.
 * \copydetails buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password, String* reservationNoteOutput)
 */
StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket) {
	return buyTicket(name, date, ticket, nullptr, nullptr);
}

/*!
 * \return E_EventDoesNotExist \b if No Event with the given name and date exists
 * \return E_TicketAlreadyBought \b if A ticket for the given row and seat has already been bought
 * \return E_TicketAlreadyReserved \b if The seat and row are reserved, but given password is nullptr
 * \return E_WrongReservationPassword \b if The seat and row are reserved, but given password is incorrect
 * \return Success \b otherwise
 */
StatusCode EventService::buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password, String* reservationNoteOutput) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count())
		return E_EventDoesNotExist;

	if (events[eInd].get_hall().get_rows() < ticket.get_row() || events[eInd].get_hall().get_seatsPerRow() < ticket.get_seat())
		return E_InvalidSeat;

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

/*!
 * Each seat in the Hall of the Event is represented by a single character, where 'R' means the seat is reserved, 'B' means the seat is bought and ' ' if it's neither.
 *
 * \return Empty String \b if No Event with the given name and date exists
 * \return Proper String \b otherwise
 */
String EventService::createSeatingString(const char* name, const Date& date, unsigned* seatsPerRow) {
	unsigned eInd = indexOfEvent(name, date);
	if (eInd == events.get_count()) {
		return "";
	}

	unsigned rowCount = events[eInd].get_hall().get_rows(), seatsCount = events[eInd].get_hall().get_seatsPerRow();
	*seatsPerRow = seatsCount;

	String out(rowCount * seatsCount);

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

	return out;
}

unsigned indexToInsertWhenTicketSort(const List<Event>& elem, unsigned topN, unsigned ticketCount) {
	for (unsigned i = 0; i < elem.get_count() && i < topN; i++) {
		if (elem[i].get_tickets().get_count() <= ticketCount)
			return i;
	}
	return (topN < elem.get_count()) ? topN : elem.get_count();
}

/*!
 * Events are sorted from index 0 to last index decreasingly by number of watchers.
 * Watchers count for an Event is the amount of bought tickets.
 *
 * If there are less events than topN, all events are returned.
 */
List<Event> EventService::queryMostWatched(unsigned topN) {
	List<Event> result;
	for (unsigned i = 0; i < events.get_count(); i++) {
		unsigned ind = indexToInsertWhenTicketSort(result, topN, events[i].get_tickets().get_count());
		if (ind < topN)
			result.insertAt(events[i], ind);
		if (result.get_count() > topN)
			result.removeAt(topN);
	}
	return result;
}

List<Event> EventService::queryInsufficientlyVisited() {
	List<Event> result;
	for (unsigned i = 0; i < events.get_count(); i++) {
		if (events[i].get_tickets().get_count() < events[i].get_hall().get_rows() * events[i].get_hall().get_seatsPerRow() / 10)
			result.add(events[i]);
	}
	return result;
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

/*! \param name C-style string, if it is equal to "ALL", reservations from all Events on the given date will be reported
 *  \param date If day, month and year are equal to 0, reservations from all dates will be reported
 *
 *  Report is saved in a file in the current directory, named "report-NAME-DATE.txt",
 *  where NAME is the given name, and DATE is the given date or "ALL" if the date is 0/0/0
 *
 *  All Events are inserted into the file with the << operator and a setting of 0b00101.
 *
 *  \return E_FileCouldNotBeOpened \b if Report file couldn't be created
 *  \return Success \b otherwise
 */
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

	String outFileName("report-");
	(outFileName += name) += "-";
	if (date.compare(Date(0, 0, 0)) == 0)
		outFileName += "ALL";
	else
		outFileName += date.createString().get_cstr();
	outFileName += ".txt";

	std::ofstream outFile(outFileName.get_cstr());
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	configureEventInsertionOp(0b00101);
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

/*! \param hallNumber Number of the Event's Hall
 *  \param start Starting Date from which to take Events
 *  \param end Ending Date until which to take Evnets (including)
 *
 *  Report is saved in a file named "boughtTickets.txt" in the current directory.
 *
 *  All Events are inserted into the file with the << operator and a setting of 0b01001.
 *
 *  \return E_FileCouldNotBeOpened \b if Report file couldn't be created
 *  \return Success \b otherwise
 */
StatusCode EventService::reportBoughtTickets(int hallNumber, const Date& start, const Date& end, bool all) {
	List<Event> result;
	bool (*cond_hall)(const Event&, int) = cond_event_hallNumber;
	if (all) cond_hall = cond_event_all;

	for (unsigned i = 0; i < events.get_count(); i++) {
		if (cond_hall(events[i], hallNumber) && cond_event_dates(events[i], start, end))
			result.add(events[i]);
	}

	std::ofstream outFile("boughtTickets.txt");
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	configureEventInsertionOp(0b01001);
	outFile << result;
	outFile.close();

	return Success;

}

/*!
 * Looks for file named "eventsDatabse.fmits", which is just a binary file, and then reads it with the "read" function in events List.
 *
 * \return E_FileCouldNotBeOpened \b if The files couldn't be opened/Doesn't exist
 * \return Success \b otherwise
 */
StatusCode EventService::load() {
	std::ifstream inFile("eventsDatabase.fmits");
	if (!inFile.is_open())
		return E_FileCouldNotBeOpened;

	events.read(inFile);
	inFile.close();
	return Success;
}

/*!
 * Looks for file named "eventsDatabse.fmits", which is just a binary file, and then writes to it with the "write" function in events List.
 *
 * \return E_FileCouldNotBeOpened \b if The files couldn't be opened
 * \return Success \b otherwise
 */
StatusCode EventService::save() {
	std::ofstream outFile("eventsDatabase.fmits");
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	events.write(outFile);
	outFile.close();
	return Success;
}
