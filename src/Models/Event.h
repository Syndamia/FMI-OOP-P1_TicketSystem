#ifndef HEADER_EVENTSYSTEM_EVENT
#define HEADER_EVENTSYSTEM_EVENT

#include "../Generic/List/OrderedList.hpp"
#include "../Generic/Date/Date.h"
#include "../Generic/String/String.h"
#include "Hall.h"
#include "Ticket.h"
#include "Reservation.h"

class Event {
	const Hall* hall;
	String name;
	Date date;
	OrderedList<Ticket> tickets;
	OrderedList<Reservation> reservations;

public:
	Event();
	Event(const Hall* hall, String name, Date date);

	const Hall& get_hall() const;
	const String& get_name() const;
	const Date& get_date() const;
	const OrderedList<Ticket>& get_tickets() const;
	const OrderedList<Reservation>& get_reservations() const;

	int compare(const Event& other);
};

#endif
