#ifndef HEADER_MODEL_RESERVATION
#define HEADER_MODEL_RESERVATION

/*! \file Reservation.h
 *  \brief Stores the declaration of class Reservation
 */

#include "Ticket.h"
#include <istream>
#include <ostream>

#define PASSWORD_LEN 8
#define NOTE_LEN 32

/*! \brief Each Reservations contains a ticket, a password and a note
 */
class Reservation {
	Ticket ticket;
	char password[PASSWORD_LEN];
	char note[NOTE_LEN];

public:
	//! Sets ticket as default value and leaves password and note blank
	Reservation();
	//! Sets ticket and leaves password and note blank
	Reservation(const Ticket& ticket);
	//! Sets ticket, password and note
	Reservation(const Ticket& ticket, const char* password, const char* note);

	//! Returns constant reference to ticket
	const Ticket& get_ticket() const;
	//! Returns constant C-style string to password
	const char* get_password() const;
	//! Returns constant C-style string to note
	const char* get_note() const;

	//! Reads Reservation from stream
	void read(std::istream& istr);
	//! Writes Reservation to stream
	void write(std::ostream& ostr) const;
	//! Compares two Reservations
	int compare(const Reservation& other) const;

	//! Reads Reservation from stream with >> operator
	friend std::istream& operator>>(std::istream& istr, Reservation& reservation);
	//! Writes Reservation to stream with << operator
	friend std::ostream& operator<<(std::ostream& ostr, const Reservation& reservation);
};

#endif
