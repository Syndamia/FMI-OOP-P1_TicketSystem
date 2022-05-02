#ifndef HEADER_EVENTSYSTEM_EVENT
#define HEADER_EVENTSYSTEM_EVENT

#include "../List/List.h"
#include "../DateTime/DateTime.h"
#include "../String/String.h"
#include "Ticket.h"
#include "Reservation.h"

class Event {
	List<Ticket> tickets;
	List<Reservation> reservations;
};

#endif
