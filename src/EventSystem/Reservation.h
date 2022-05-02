#ifndef HEADER_EVENTSYSTEM_RESERVATION
#define HEADER_EVENTSYSTEM_RESERVATION

#include "Ticket.h"
#include <istream>
#include <ostream>

class Reservation {
	Ticket ticket;
	char password[8];
	char note[32];

public:
	Reservation(const Ticket& ticket, const char* password, const char* note);

	void read(std::istream& istr);
	void write(std::ostream& ostr) const;
};

#endif
