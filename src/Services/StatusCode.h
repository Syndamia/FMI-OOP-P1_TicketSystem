#ifndef HEADER_SERVICES_STATUSCODE
#define HEADER_SERVICES_STATUSCODE

enum StatusCode {
	Success,


	W_TicketHadNotBeenReserved,


	E_FileCouldNotBeOpened,

	E_HallDoesntExist,

	E_EventWillOverlap,
	E_EventDoesNotExist,

	E_TicketAlreadyBought,
	E_TicketAlreadyReserved,
	E_ReservationDoesNotExist,
	E_WrongReservationPassword,
};

#endif
