#ifndef HEADER_EVENTSYSTEM_TICKET
#define HEADER_EVENTSYSTEM_TICKET

#include <istream>
#include <ostream>

class Ticket {
	unsigned row;
	unsigned seat;

public:
	Ticket();
	Ticket(unsigned row, unsigned seat);

	unsigned get_row() const;
	unsigned get_seat() const;

	void read(std::istream& istr);
	void write(std::ostream& ostr) const;
	int compare(const Ticket& other) const;
};

std::istream& operator>>(std::istream& istr, Ticket& ticket);
std::ostream& operator<<(std::ostream& ostr, const Ticket& ticket);

#endif
