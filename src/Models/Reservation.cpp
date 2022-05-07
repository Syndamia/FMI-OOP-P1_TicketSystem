#include "Reservation.h"
#include <cstring>

Reservation::Reservation() : Reservation(Ticket(), "", "") {}

Reservation::Reservation(const Ticket& ticket) : Reservation(ticket, "", "") {}

Reservation::Reservation(const Ticket& ticket, const char* password, const char* note) {
	this->ticket = ticket;
	strncpy(this->password, password, PASSWORD_LEN);
	strncpy(this->note, note, NOTE_LEN);
}

const Ticket& Reservation::get_ticket() const {
	return ticket;
}

void Reservation::read(std::istream& istr) {
	ticket.read(istr);
	istr.read(password, sizeof(password));
	istr.read(note, sizeof(note));
}

void Reservation::write(std::ostream& ostr) const {
	ticket.write(ostr);
	ostr.write(password, sizeof(password));
	ostr.write(note, sizeof(note));
}

int Reservation::compare(const Reservation& other) const {
	return ticket.compare(other.ticket);
}
