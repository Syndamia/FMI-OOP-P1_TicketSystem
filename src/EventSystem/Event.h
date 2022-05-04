#ifndef HEADER_EVENTSYSTEM_EVENT
#define HEADER_EVENTSYSTEM_EVENT

#include "../List/OrderedList.hpp"
#include "../DateTime/DateTime.h"
#include "../String/String.h"
#include "../Venue/Hall.h"
#include "Ticket.h"
#include "Reservation.h"
#include "StatusCodes.h"

class Event {
	OrderedList<Ticket> tickets;
	OrderedList<Reservation> reservations;
	DateTime time;
	String name;
	const Hall* hall;

public:
	Event();
	Event(const Hall* hall, String name, DateTime time);

	StatusCode reserveTicket(const Ticket& ticket, const char* password, const char* note);

	StatusCode cancelReservation(const Ticket& ticket);

	StatusCode buyTicket(const Ticket& ticket);

	StatusCode buyTicketFromReservation(const Reservation& reservation, const char* password);
};

#endif
