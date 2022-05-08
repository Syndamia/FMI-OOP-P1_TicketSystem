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

/*! \param istr An input stream
 *
 * Directly reads bytes from stream (calls read() function).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ifstream
 */
void Ticket::read(std::istream& istr) {
	istr.read((char*)&row, sizeof(row));
	istr.read((char*)&seat, sizeof(seat));
}

/*! \param ostr An output stream
 *
 * Directly writes bytes to stream (calls write() function).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ofstream
 */
void Ticket::write(std::ostream& ostr) const {
	ostr.write((const char*)&row, sizeof(row));
	ostr.write((const char*)&seat, sizeof(seat));
}

/*! \return If rows are equal, -1 if seat < other.seat, 1 if seat > other.seat, 0 if seat == other.seat, else the same, but for rows
 */
int Ticket::compare(const Ticket& other) const {
	if (row == other.row)
		return (seat > other.seat) - (seat < other.seat);
	return (row > other.row) - (row < other.row);
}

/* Outside of class */

/*!
 * Uses the stream's >> operator to read and parse row and seat.
 *
 * \note Best used with std::cin or text std::ifstream
 */
std::istream& operator>>(std::istream& istr, Ticket& ticket) {
	unsigned row, seat;
	istr >> row >> seat;
	ticket = Ticket(row, seat);
	return istr;
}

/*!
 * Uses the stream's << operator to write row and seat, separated by a space.
 *   
 * \note Best used with std::cout or text std::ofstream
 */
std::ostream& operator<<(std::ostream& ostr, const Ticket& ticket) {
	return ostr << ticket.get_row() << " " << ticket.get_seat();
}
