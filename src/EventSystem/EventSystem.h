#ifndef HEADER_EVENTSYSTEM
#define HEADER_EVENTSYSTEM

#include "../List/OrderedList.hpp"
#include "../DateTime/DateTime.h"

#include "Event.h"
#include "StatusCodes.h"

class EventSystem {
	OrderedList<Event> events;
	unsigned indSoonestUpcoming;

	void updateSoonestUpcoming();

public:
	EventSystem();
	EventSystem(const Event* events, unsigned eventCount);

	StatusCode createEvent(const Hall* hall, String name, DateTime time);
	StatusCode cancelEvent();

	StatusCode reserveTicket(unsigned eventIndex, char* note, unsigned seatRow, unsigned seatColumn);
	StatusCode cancelTicketReservation();
	StatusCode buyTicket();

	void queryUpcoming(unsigned hallIndex);
	unsigned queryFreeSeats(const char* name, const DateTime& dt);
	void queryReservations(unsigned eventIndex);
	void queryBoughtTickets(DateTime start, DateTime end, unsigned hall);
	void queryMostVisited();
	void queryInsufficientlyVisited();
	void reportReservations(unsigned eventIndex);
};

#endif
