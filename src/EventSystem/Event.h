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
	Hall* hall;

public:
	Event();
	Event(const Hall* hall, String name, DateTime time);

	StatusCode reserveTicket();
	StatusCode cancelReservation();
	StatusCode buyReservation();
};

#endif
