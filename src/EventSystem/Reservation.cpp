#include "Reservation.h"
#include <cstring>

Reservation::Reservation(const Ticket& ticket, const char* password, const char* note) {
	this->ticket = ticket;
	strcpy(this->password, password);
	strcpy(this->note, note);
}
