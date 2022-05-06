#ifndef HEADER_EVENTSYSTEM_STATUSCODES
#define HEADER_EVENTSYSTEM_STATUSCODES

enum StatusCode {
	Success,


	W_TicketHadNotBeenReserved,


	E_Generic,
	E_DoesntExist,

	E_HallDoesntExist,

	E_EventWillOverlap,
	E_EventDoesNotExist,

	E_TicketAlreadyBought,
	E_TicketAlreadyReserved,
	E_ReservationDoesNotExist,
	E_WrongReservationPassword,
};

#endif
