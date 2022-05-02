#include "Reservation.h"
#include <cstring>

Reservation::Reservation() : Reservation(Ticket(), "", "") {}

Reservation::Reservation(const Ticket& ticket, const char* password, const char* note) {
	this->ticket = ticket;
	strcpy(this->password, password);
	strcpy(this->note, note);
}

void Reservation::read(std::istream& istr) {
	ticket.read(istr);
	istr.read(password, sizeof(char) * 8);
	istr.read(note, sizeof(char) * 32);
}
