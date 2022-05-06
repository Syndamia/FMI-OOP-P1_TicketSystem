#ifndef HEADER_EVENTSYSTEM_EVENT
#define HEADER_EVENTSYSTEM_EVENT

#include "../List/OrderedList.hpp"
#include "../Date/Date.h"
#include "../String/String.h"
#include "../Venue/Hall.h"
#include "Ticket.h"
#include "Reservation.h"
#include "StatusCodes.h"

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

	StatusCode reserveTicket(const Ticket& ticket, const char* password, const char* note);

	StatusCode cancelReservation(unsigned row, unsigned seat);
	StatusCode cancelReservation(const Ticket& ticket);

	StatusCode buyTicket(const Ticket& ticket);

	StatusCode buyTicketFromReservation(const Reservation& reservation, const char* password);

	int compare(const Event& other);
};

#endif
