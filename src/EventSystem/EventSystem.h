#ifndef HEADER_EVENTSYSTEM
#define HEADER_EVENTSYSTEM

#include "../List/OrderedList.hpp"
#include "../Date/Date.h"

#include "Event.h"
#include "StatusCodes.h"

class EventSystem {
	OrderedList<Event> events;
	unsigned indSoonestUpcoming;

	void updateSoonestUpcoming();
	unsigned indexOfEvent(const Date& dt);
	unsigned indexOfEvent(const char* name, const Date& dt);

public:
	EventSystem();
	EventSystem(const Event* events, unsigned eventCount);

	StatusCode createEvent(const Hall* hall, String name, Date date);
	StatusCode cancelEvent(const char* name, Date date);

	StatusCode reserveTicket(unsigned eventIndex, char* note, unsigned seatRow, unsigned seatColumn);
	StatusCode cancelTicketReservation();
	StatusCode buyTicket();

	void queryUpcoming(unsigned hallIndex);
	List<Ticket> queryFreeTickets(const char* name, const Date& dt);
	void queryReservations(unsigned eventIndex);
	void queryBoughtTickets(Date start, Date end, unsigned hall);
	void queryMostVisited();
	void queryInsufficientlyVisited();
	void reportReservations(unsigned eventIndex);
};

#endif
