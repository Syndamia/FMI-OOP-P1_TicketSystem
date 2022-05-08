#include "Reservation.h"
#include <cstring>

Reservation::Reservation() : Reservation(Ticket(), "", "") {}

Reservation::Reservation(const Ticket& ticket) : Reservation(ticket, "", "") {}

Reservation::Reservation(const Ticket& ticket, const char* password, const char* note) {
	this->ticket = ticket;
	strncpy(this->password, password, PASSWORD_LEN);
	strncpy(this->note, note, NOTE_LEN);
}

const Ticket& Reservation::get_ticket() const {
	return ticket;
}

const char* Reservation::get_password() const {
	return password;
}

const char* Reservation::get_note() const {
	return note;
}

/*! \param istr An input stream
 *
 * Directly reads bytes from stream (calls read() function).
 * Uses ticket's read() function.
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ifstream
 */
void Reservation::read(std::istream& istr) {
	ticket.read(istr);
	istr.read(password, sizeof(password));
	istr.read(note, sizeof(note));
}

/*! \param ostr An output stream
 *
 * Directly writes bytes to stream (calls write() function).
 * Uses ticket's write() function.
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ofstream
 */
void Reservation::write(std::ostream& ostr) const {
	ticket.write(ostr);
	ostr.write(password, sizeof(password));
	ostr.write(note, sizeof(note));
}

/*! \return Compares tickets
 */
int Reservation::compare(const Reservation& other) const {
	return ticket.compare(other.ticket);
}

/*!
 * Uses the stream's >> operator to read and parse the ticket.
 * Password and note are left blank.
 *
 * \note Best used with std::cin or text std::ifstream
 */
std::istream& operator>>(std::istream& istr, Reservation& reservation) {
	strncpy(reservation.password, "", PASSWORD_LEN);
	strncpy(reservation.note, "", NOTE_LEN);
	return istr >> reservation.ticket;
}

/*!
 * Uses the stream's << operator to write the ticket only.
 *   
 * \note Best used with std::cout or text std::ofstream
 */
std::ostream& operator<<(std::ostream& ostr, const Reservation& reservation) {
	return ostr << reservation.ticket;
}
