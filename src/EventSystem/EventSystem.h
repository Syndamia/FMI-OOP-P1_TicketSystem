#ifndef HEADER_EVENTSYSTEM
#define HEADER_EVENTSYSTEM

#include "../List/List.h"
#include "../DateTime/DateTime.h"

#include "Event.h"
#include "StatusCodes.h"

class EventSystem {
	List<Event> events;
	unsigned indSoonestUpcoming;

public:
	EventSystem(const Event* events, unsigned eventCount);

	StatusCode createEvent();
	StatusCode cancelEvent();

	StatusCode reserveTicket(char* note, DateTime time, unsigned seatRow, unsigned seatColumn);
	StatusCode cancelTicketReservation();
	StatusCode buyTicket();

	void queryUpcoming(unsigned hallIndex);
	unsigned queryFreeSeats(const Event& event);
	void queryReservations(const Event& event);
};

#endif
