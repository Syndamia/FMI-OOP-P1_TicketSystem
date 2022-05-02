#include "Ticket.h"

Ticket::Ticket() : Ticket(0, 0) {}

Ticket::Ticket(unsigned row, unsigned seat) {
	this->row = row;
	this->seat = seat;
}

unsigned Ticket::get_row() const {
	return row;
}

unsigned Ticket::get_seat() const {
	return seat;
}
