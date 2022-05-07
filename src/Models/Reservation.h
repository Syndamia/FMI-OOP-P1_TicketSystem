#ifndef HEADER_EVENTSYSTEM_RESERVATION
#define HEADER_EVENTSYSTEM_RESERVATION

#include "Ticket.h"
#include <istream>
#include <ostream>

#define PASSWORD_LEN 8
#define NOTE_LEN 32

class Reservation {
	Ticket ticket;
	char password[PASSWORD_LEN];
	char note[NOTE_LEN];

public:
	Reservation();
	Reservation(const Ticket& ticket);
	Reservation(const Ticket& ticket, const char* password, const char* note);

	const Ticket& get_ticket() const;
	const char* get_password() const;
	const char* get_note() const;

	void read(std::istream& istr);
	void write(std::ostream& ostr) const;
	int compare(const Reservation& other) const;

	friend std::istream& operator>>(std::istream& istr, Reservation& reservation);
	friend std::ostream& operator<<(std::ostream& ostr, const Reservation& reservation);
};

#endif
