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

void Ticket::read(std::istream& istr) {
	istr.read((char*)&row, sizeof(row));
	istr.read((char*)&row, sizeof(seat));
}

void Ticket::write(std::ostream& ostr) const {
	ostr.write((const char*)&row, sizeof(row));
	ostr.write((const char*)&seat, sizeof(seat));
}