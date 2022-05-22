#ifndef HEADER_SERVICES_STATUSCODE
#define HEADER_SERVICES_STATUSCODE

/*! \file StatusCode.h
 *  \brief Stores declaration of enum StatusCode
 */

/*! \brief Used for communication between Services and what uses them
 *
 * Most functions in Services return a StatusCode.
 *
 * Those starting with W should be considered Warning, and those starting with E should be considered Errors.
 */
enum StatusCode {
	Success,


	W_TicketHadNotBeenReserved,


	E_FileCouldNotBeOpened,

	E_HallDoesntExist,

	E_EventWillOverlap,
	E_EventDoesNotExist,

	E_InvalidSeat,
	E_TicketAlreadyBought,
	E_TicketAlreadyReserved,
	E_ReservationDoesNotExist,
	E_WrongReservationPassword,
};

#endif
