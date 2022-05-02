#ifndef HEADER_EVENTSYSTEM_EVENT
#define HEADER_EVENTSYSTEM_EVENT

#include "../List/List.h"
#include "../DateTime/DateTime.h"
#include "../String/String.h"
#include "../Venue/Hall.h"
#include "Ticket.h"
#include "Reservation.h"
#include "StatusCodes.h"

class Event {
	List<Ticket> tickets;
	List<Reservation> reservations;
	DateTime time;
	String name;
	const Hall* hall;

public:
	Event();
	Event(const Hall* hall, String name, DateTime time);

	StatusCode reserveTicket(const Ticket& ticket, const char* password, const char* note);

	StatusCode cancelReservation(const Ticket& ticket);

	StatusCode buyReservation(const Reservation& reservation, const char* password);
};

#endif
