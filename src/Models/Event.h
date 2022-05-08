#ifndef HEADER_MODEL_EVENT
#define HEADER_MODEL_EVENT

/*! \file Event.h
 *  \brief Stores the declaration of class Event
 */

#include "../Generic/List/OrderedList.hpp"
#include "../Generic/Date/Date.h"
#include "../Generic/String/String.h"
#include "Hall.h"
#include "Ticket.h"
#include "Reservation.h"
#include <istream>
#include <ostream>

/*! \brief Stores an event's hall, name, date, bought tickets and reservations
 */
class Event {
	Hall hall;
	String name;
	Date date;
	OrderedList<Ticket> tickets;
	OrderedList<Reservation> reservations;

public:
	//! Calls default constructors on data
	Event();
	//! Copies given hall and sets name and date
	Event(const Hall& hall, String name, Date date);

	//! Returns constant reference Hall in which event will be held
	const Hall& get_hall() const;
	//! Returns constant reference to name of event
	const String& get_name() const;
	//! Returns constant reference to date on which event will be held
	const Date& get_date() const;

	//! Returns reference to bought tickets
	OrderedList<Ticket>& get_tickets();
	//! Returns constant reference to bought tickets
	const OrderedList<Ticket>& get_tickets() const;
	//! Returns reference to reservations
	OrderedList<Reservation>& get_reservations();
	//! Returns constant reference to reservations
	const OrderedList<Reservation>& get_reservations() const;

	//! Reads Event from stream
	void read(std::istream& istr);
	//! Writes Event to stream
	void write(std::ostream& ostr);
	//! Compares two events
	int compare(const Event& other);
};

//! Reads Event from stream with >> operator
std::istream& operator>>(std::istream& istr, Event& event);
//! Configures how Event should be shown, when written to stream with << operator
void configureEventInsertionOp(unsigned setting);
//! Writes Event to stream with << operator
std::ostream& operator<<(std::ostream& ostr, const Event& event);

#endif
