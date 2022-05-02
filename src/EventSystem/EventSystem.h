#ifndef HEADER_EVENTSYSTEM
#define HEADER_EVENTSYSTEM

#include "../List/OrderedList.h"
#include "../DateTime/DateTime.h"

#include "Event.h"
#include "StatusCodes.h"

class EventSystem {
	OrderedList<Event> events;
	unsigned indSoonestUpcoming;

public:
	EventSystem(const Event* events, unsigned eventCount);

	StatusCode createEvent();
	StatusCode cancelEvent();

	StatusCode reserveTicket(unsigned eventIndex, char* note, unsigned seatRow, unsigned seatColumn);
	StatusCode cancelTicketReservation();
	StatusCode buyTicket();

	void queryUpcoming(unsigned hallIndex);
	unsigned queryFreeSeats(unsigned eventIndex);
	void queryReservations(unsigned eventIndex);
	void queryBoughtTickets(DateTime start, DateTime end, unsigned hall);
	void queryMostVisited();
	void queryInsufficientlyVisited();
	void reportReservations(unsigned eventIndex);
};

#endif
