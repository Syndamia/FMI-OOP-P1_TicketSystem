#ifndef HEADER_MODEL_EVENT
#define HEADER_MODEL_EVENT

#include "../Generic/List/OrderedList.hpp"
#include "../Generic/Date/Date.h"
#include "../Generic/String/String.h"
#include "Hall.h"
#include "Ticket.h"
#include "Reservation.h"
#include <istream>
#include <ostream>

class Event {
	Hall hall;
	String name;
	Date date;
	OrderedList<Ticket> tickets;
	OrderedList<Reservation> reservations;

public:
	Event();
	Event(const Hall& hall, String name, Date date);

	const Hall& get_hall() const;
	const String& get_name() const;
	const Date& get_date() const;

	OrderedList<Ticket>& get_tickets();
	const OrderedList<Ticket>& get_tickets() const;
	OrderedList<Reservation>& get_reservations();
	const OrderedList<Reservation>& get_reservations() const;

	void write(std::ostream& ostr);
	void read(std::istream& istr);

	int compare(const Event& other);
};

std::istream& operator>>(std::istream& istr, Event& event);
void configureEventInsertionOp(unsigned setting);
std::ostream& operator<<(std::ostream& ostr, const Event& event);

#endif
