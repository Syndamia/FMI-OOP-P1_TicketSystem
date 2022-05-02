#ifndef HEADER_EVENTSYSTEM_EVENT
#define HEADER_EVENTSYSTEM_EVENT

#include "../List/List.h"
#include "Ticket.h"
#include "Reservation.h"

class Event {
	List<Ticket> tickets;
	List<Reservation> reservations;
};

#endif