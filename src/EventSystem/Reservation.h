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
	Reservation();
	Reservation(const Ticket& ticket);
	Reservation(const Ticket& ticket, const char* password, const char* note);

	bool validPassword(const char* password) const;
	const Ticket& get_ticket() const;

	void read(std::istream& istr);
	void write(std::ostream& ostr) const;
	int compare(const Reservation& other) const;
};

#endif
