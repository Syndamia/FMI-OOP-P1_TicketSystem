#ifndef HEADER_HEADER_TICKET
#define HEADER_HEADER_TICKET

/*! \file Ticket.h
 *  \brief Stores the declaration of class Ticket
 */

#include <istream>
#include <ostream>

/*! \brief Each Ticket contains a row and a seat number
 */
class Ticket {
	unsigned row;
	unsigned seat;

public:
	//! Sets row and seat to zeroes
	Ticket();
	//! Sets row and seat
	Ticket(unsigned row, unsigned seat);

	//! Returns row
	unsigned get_row() const;
	//! Returns seat
	unsigned get_seat() const;

	//! Reads Ticket from stram
	void read(std::istream& istr);
	//! Writes Ticket to stream
	void write(std::ostream& ostr) const;
	//! Compares two Tickets
	int compare(const Ticket& other) const;
};

//! Reads Ticket from stream with >> operator
std::istream& operator>>(std::istream& istr, Ticket& ticket);
//! Writes Ticket to stream with << operator
std::ostream& operator<<(std::ostream& ostr, const Ticket& ticket);

#endif
