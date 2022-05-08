#ifndef HEADER_SERVICE_STATUSCODE
#define HEADER_SERVICE_STATUSCODE

enum StatusCode {
	Success,


	W_TicketHadNotBeenReserved,


	E_DoesntExist,
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
