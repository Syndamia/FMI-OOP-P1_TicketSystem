#ifndef HEADER_SERVICES_EVENTSERVICE
#define HEADER_SERVICES_EVENTSERVICE

/*! \file EventService.h
 *  \brief Stores the declaration of class EventService
 */

#include "../Generic/List/OrderedList.hpp"
#include "../Generic/Date/Date.h"
#include "../Models/Event.h"
#include "HallService.h"
#include "StatusCode.h"

/*! \brief Each EventService stores all events and a pointer to HallService
 */
class EventService {
	OrderedList<Event> events;

	const HallService* hs;

	unsigned indexOfEvent(const char* name, const Date& date);

public:
	//! Sets HallService pointer and initializes events List
	EventService(const HallService* hs);
	//! Sets HallService pointer and copies values from events into events List
	EventService(const HallService* hs, const Event* events, unsigned eventCount);

	//! Creates an Event, with the given hallNumber, name and date
	StatusCode createEvent(int hallNumber, const String& name, const Date& date);
	//! Cancels an Event with the given name and date
	StatusCode cancelEvent(const char* name, const Date& date);

	//! Creates a Reservation for an Event by name and date
	StatusCode reserveTicket(const char* name, const Date& date, const char* password, const char* note, const Ticket& ticket);
	//! Cancels a Reservation for a ticket
	StatusCode cancelTicketReservation(const char* name, const Date& date, const Ticket& ticket);
	//! Whether a ticket is a reserved or not
	StatusCode ticketIsReserved(const char* name, const Date& date, const Ticket& ticket);

	//! Buys ticket, assuming it is reserved and stores the reservation note
	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket, const char* password, String* reservationNoteOutput);
	//! Buys ticket, assuming it isn't reserved
	StatusCode buyTicket(const char* name, const Date& date, const Ticket& ticket);

	//! Creates a special String for status of all seats in given Event (by name and date) and returns seatsPerRow in given pointer
	String createSeatingString(const char* name, const Date& date, unsigned* seatsPerRow);

	//! \return A List of topN most watched Events
	List<Event> queryMostWatched(unsigned topN);
	//! \return A List of events which have attracted sales of less than 10% of the Hall's seat
	List<Event> queryInsufficientlyVisited();

	//! Creates a report that lists all Events (with given name and date) and their reserved tickets
	StatusCode reportReservations(const char* name, const Date& date);
	//! Creates a report that Lists all Events (with given name and date) and number of bought tickets
	StatusCode reportBoughtTickets(int hallNumber, const Date& start, const Date& end, bool all = false);

	//! Loads Events from a database file
	StatusCode load();
	//! Saves Events to a database file
	StatusCode save();
};

#endif
