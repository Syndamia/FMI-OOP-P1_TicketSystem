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

	StatusCode reserveTicket(const char* name, const Date& date, const char* password, const char* note, unsigned seatRow, unsigned seatColumn);
	StatusCode reserveTicket(const char* name, const Date& date, const char* password, const char* note, const Ticket& ticket);

	StatusCode cancelTicketReservation(const char* name, const Date& date, unsigned seatRow, unsigned seatColumn);
	StatusCode cancelTicketReservation(const char* name, const Date& date, const Ticket& ticket);

	StatusCode buyTicket(const char* name, const Date& date, unsigned row, unsigned seat);
	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket);
	StatusCode buyTicket(const char* name, const Date& date, unsigned row, unsigned seat, const char* password);
	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password);

	const Hall* queryEventHall(const char* name, const Date& date);
	OrderedList<Ticket> queryTickets(const char* name, const Date& date);
	OrderedList<Reservation> queryReservations(const char* name, const Date& date);

	void queryMostVisited();
	void queryInsufficientlyVisited();
	void reportBoughtTickets(Date start, Date end, unsigned hall);
	void reportReservations(unsigned eventIndex);
};

#endif
