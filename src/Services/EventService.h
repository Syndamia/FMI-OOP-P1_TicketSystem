#ifndef HEADER_SERVICE_EVENTSERVICE
#define HEADER_SERVICE_EVENTSERVICE

#include "../Generic/List/OrderedList.hpp"
#include "../Generic/Date/Date.h"
#include "../Models/Event.h"
#include "HallService.h"
#include "StatusCode.h"

class EventService {
	OrderedList<Event> events;
	unsigned indSoonestUpcoming;

	const HallService* hs;

	void updateSoonestUpcoming();
	unsigned indexOfEvent(const char* name, const Date& date);

public:
	EventService(const HallService* hs);
	EventService(const HallService* hs, const Event* events, unsigned eventCount);

	StatusCode createEvent(int hallNumber, const String& name, const Date& date);
	StatusCode cancelEvent(const char* name, const Date& date);

	StatusCode reserveTicket(const char* name, const Date& date, const char* password, const char* note, const Ticket& ticket);

	StatusCode cancelTicketReservation(const char* name, const Date& date, const Ticket& ticket);

	StatusCode ticketIsReserved(const char* name, const Date& date, const Ticket& ticket);

	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password, String* reservationNoteOutput);
	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket);

	String createSeatingString(const char* name, const Date& date, unsigned* seatsPerRow);

	List<Event> queryMostWatched(unsigned topN);
	void queryInsufficientlyVisited();

	StatusCode reportReservations(const char* name, const Date& date);
	StatusCode reportBoughtTickets(int hallNumber, const Date& start, const Date& end, bool all = false);

	StatusCode load();
	StatusCode save();
};

#endif
