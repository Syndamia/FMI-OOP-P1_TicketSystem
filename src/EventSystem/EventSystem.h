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
	unsigned indexOfEvent(const Date& date);
	unsigned indexOfEvent(const char* name, const Date& date);

public:
	EventSystem();
	EventSystem(const Event* events, unsigned eventCount);

	StatusCode createEvent(const Hall* hall, String name, Date date);
	StatusCode cancelEvent(const char* name, const Date& date);

	StatusCode reserveTicket(const char* name, const Date& date, const char* password, const char* note, unsigned seatRow, unsigned seatColumn);
	StatusCode reserveTicket(const char* name, const Date& date, const char* password, const char* note, const Ticket& ticket);

	StatusCode cancelTicketReservation(const char* name, const Date& date, unsigned seatRow, unsigned seatColumn);
	StatusCode cancelTicketReservation(const char* name, const Date& date, const Ticket& ticket);

	StatusCode buyTicket(const char* name, const Date& date, unsigned row, unsigned seat);
	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket);
	StatusCode buyTicket(const char* name, const Date& date, unsigned row, unsigned seat, const char* password);
	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password);

	// List<Ticket> queryFreeTickets(const char* name, const Date& date);
	List<Reservation> queryReservations(unsigned eventIndex);
	void queryBoughtTickets(Date start, Date end, unsigned hall);
	void queryMostVisited();
	void queryInsufficientlyVisited();
	void reportReservations(unsigned eventIndex);
};

#endif
