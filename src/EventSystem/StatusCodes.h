#ifndef HEADER_EVENTSYSTEM_STATUSCODES
#define HEADER_EVENTSYSTEM_STATUSCODES

enum StatusCode {
	Success,


	W_TicketWasNotReserved,


	E_Generic,
	E_DoesntExist,

	E_EventWillOverlap,

	E_TicketAlreadyBought,
	E_TicketAlreadyReserved,
	E_WrongTicketPassword,
};

#endif
