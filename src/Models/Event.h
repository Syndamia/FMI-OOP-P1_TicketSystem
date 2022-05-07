#ifndef HEADER_EVENTSYSTEM_EVENT
#define HEADER_EVENTSYSTEM_EVENT

#include "../Generic/List/OrderedList.hpp"
#include "../Generic/Date/Date.h"
#include "../Generic/String/String.h"
#include "Hall.h"
#include "Ticket.h"
#include "Reservation.h"
#include <istream>
#include <ostream>

class Event {
	const Hall* hall;
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
	OrderedList<Reservation>& get_reservations();

	void print(std::ostream& ostr);
	void write(std::istream& istr);

	int compare(const Event& other);

	friend std::istream& operator>>(std::istream& istr, Event& event);
	friend std::ostream& operator<<(std::ostream& ostr, Event& event);
};

#endif
