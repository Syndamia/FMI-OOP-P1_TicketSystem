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
	OrderedList<Ticket> tickets;
	OrderedList<Reservation> reservations;
	Date date;
	String name;
	const Hall* hall;

public:
	Event();
	Event(const Hall* hall, String name, Date date);

	const OrderedList<Ticket>& get_tickets() const;
	const OrderedList<Reservation>& get_reservations() const;
	const Hall& get_hall() const;
	const String& get_name() const;
	const Date& get_date() const;

	StatusCode reserveTicket(const Ticket& ticket, const char* password, const char* note);

	StatusCode cancelReservation(unsigned row, unsigned seat);
	StatusCode cancelReservation(const Ticket& ticket);

	StatusCode buyTicket(const Ticket& ticket);

	StatusCode buyTicketFromReservation(const Reservation& reservation, const char* password);

	bool ticketIsFree(unsigned row, unsigned seat);
	bool ticketIsFree(const Ticket& ticket);

	int compare(const Event& other);
};

#endif
