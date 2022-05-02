#ifndef HEADER_EVENTSYSTEM_RESERVATION
#define HEADER_EVENTSYSTEM_RESERVATION

#include "Ticket.h"

class Reservation {
	Ticket ticket;
	char password[8];
	char note[128];
};

#endif
