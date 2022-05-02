#ifndef HEADER_EVENTSYSTEM_TICKET
#define HEADER_EVENTSYSTEM_TICKET

class Ticket {
	unsigned row;
	unsigned seat;

public:
	Ticket();
	Ticket(unsigned row, unsigned seat);

	unsigned get_row() const;
	unsigned get_seat() const;
};

#endif
