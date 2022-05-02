#ifndef HEADER_EVENTSYSTEM_RESERVATION
#define HEADER_EVENTSYSTEM_RESERVATION

#include "Ticket.h"

class Reservation {
	Ticket ticket;
	char password[8];
	char note[128];

public:
	Reservation(const Ticket& ticket, const char* password, const char* note);
};

#endif
