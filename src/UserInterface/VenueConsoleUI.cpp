#include "VenueConsoleUI.h"
#include "../Generic/List/OrderedList.hpp"
#include "../Generic/String/String.h"
#include "../Generic/Date/Date.h"
#include "../Generic/ConsoleInterface/Menu.h"
#include "../Generic/ConsoleInterface/Toolbox.hpp"
#include "../Services/StatusCode.h"
#include "../Models/Reservation.h"
#include <cstring>

EventService* es;
HallService* hs;

Menu mainMenu("FMI Ticket System", true, false),
	 ticketManagementMenu("Ticket management", false, true),
	 eventManagementMenu("Event management", false, true),
	 reportsMenu("Report management", false, true);

void handleStatusCode(StatusCode sc, Menu menu) {
	switch (sc) {
		case Success:
			menu.registerSuccess("Success!"); break;
		case W_TicketHadNotBeenReserved:
			menu.registerWarning("Ticket hadn't been reserved. Nothing changed."); break;
		case E_EventDoesNotExist: 
			menu.registerError("Event doesn't exist!"); break;
		case E_EventWillOverlap:
			menu.registerError("There is already an event at same time!"); break;
		case E_TicketAlreadyBought:
			menu.registerError("Ticket was already bought!"); break;
		case E_TicketAlreadyReserved:
			menu.registerError("Ticket was already reserved!"); break;
		case E_ReservationDoesNotExist:
			menu.registerError("Reservation doesn't exist!"); break;
		case E_WrongReservationPassword:
			menu.registerError("Wrong reservation password!"); break;
		default: 
			menu.registerError("An unhandled status code was returned!"); break;
	}
}

/* Ticket Management */

void command_freeSeats() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);

	unsigned seatsPerRow = 0;
	String seating = es->createSeatingString(name, date, &seatsPerRow);
	if (seating.get_length() == 0) {
		handleStatusCode(E_EventDoesNotExist, ticketManagementMenu);
		return;
	}

	table(1, seatsPerRow, seating.get_cstr());
	pressEnterToContinue();
}

void command_reserveTicket() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	Ticket tic;
	inputSubBox("Enter row and seat: ", &tic);
	char password[PASSWORD_LEN];
	inputLineSubBox("Enter password [Max 8 characters]: ", password, PASSWORD_LEN);
	char note[NOTE_LEN];
	inputLineSubBox("Enter note [Max 32 characters]: ", note, NOTE_LEN, false);

	StatusCode s = es->reserveTicket(name, date, password, note, tic);
	handleStatusCode(s, ticketManagementMenu);
}

void command_cancelReservation() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	Ticket tic;
	inputSubBox("Enter row and seat: ", &tic);

	StatusCode s = es->cancelTicketReservation(name, date, tic);
	handleStatusCode(s, ticketManagementMenu);
}

void command_buyTicket() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	Ticket tic;
	inputSubBox("Enter row and seat: ", &tic);

	StatusCode s = es->ticketIsReserved(name, date, tic);
	if (s == Success) {
		warningSubBox("Ticket is reserved!");

		char pass[PASSWORD_LEN];
		inputLineSubBox("Enter reservation password: ", pass, PASSWORD_LEN);

		String note;
		s = es->buyTicket(name, date, tic, pass, &note);
		if (note.get_length() > 0) {
			successSubBox("The reservation had a note attached. It reads:");
			successSubBox(note.get_cstr());
			pressEnterToContinue(false);
		}
	}
	else if (s == W_TicketHadNotBeenReserved) {
		s = es->buyTicket(name, date, tic);
	}

	handleStatusCode(s, ticketManagementMenu);
}

void submenu_ticketManagement() {
	ticketManagementMenu.navigate();
}

/* Event Management */

void command_createEvent() {
	unsigned hallNumber;
	inputSubBox("Enter hall number: ", &hallNumber);
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	
	StatusCode s = es->createEvent(hallNumber, name, date);
	handleStatusCode(s, eventManagementMenu);
}

void command_cancelEvent() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);

	StatusCode s = es->cancelEvent(name, date);
	handleStatusCode(s, eventManagementMenu);
}

void command_mostWatched() {

}

void command_belowWatchers() {

}

void submenu_eventManagement() {
	eventManagementMenu.navigate();
}

/* Report Management */

void command_reservationsList() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);

	StatusCode s = es->reportReservations(name, date);
	handleStatusCode(s, reportsMenu);
}

void command_boughtTickets() {
	unsigned hallNumber;
	inputSubBox("Enter hall number: ", &hallNumber);
	Date start, end;
	inputSubBox("Enter start date: ", &start);
	inputSubBox("Enter end date: ", &end);

	StatusCode s = es->reportBoughtTickets(hallNumber, start, end, hallNumber == 0);
	handleStatusCode(s, reportsMenu);
}

void submenu_reportManagement() {
	reportsMenu.navigate();
}

/* Main */

void load() {
	StatusCode s = es->load();
	if (s == E_FileCouldNotBeOpened) {
		errorBox("Could not load events from file!");
		pressEnterToContinue();
	}
	s = hs->load();
	if (s == E_FileCouldNotBeOpened) {
		errorBox("Could not load halls from file!");
		pressEnterToContinue();
	}
}

void save() {
	StatusCode s = es->save();
	if (s == E_FileCouldNotBeOpened) {
		errorBox("Could not save events to file!");
		pressEnterToContinue();
	}
	s = hs->save();
	if (s == E_FileCouldNotBeOpened) {
		errorBox("Could not save halls to file!");
		pressEnterToContinue();
	}
}

void init() {
	mainMenu.addCommand(Command("Ticket Management", submenu_ticketManagement));
	mainMenu.addCommand(Command("Event Management", submenu_eventManagement));
	mainMenu.addCommand(Command("Report Management", submenu_reportManagement));

	ticketManagementMenu.addCommand(Command("Print Seats", command_freeSeats));
	ticketManagementMenu.addCommand(Command("Reserve Ticket", command_reserveTicket));
	ticketManagementMenu.addCommand(Command("Cancel Ticket Reservation", command_cancelReservation));
	ticketManagementMenu.addCommand(Command("Buy Ticket", command_buyTicket));

	eventManagementMenu.addCommand(Command("Create Event", command_createEvent));
	eventManagementMenu.addCommand(Command("Cancel Event", command_cancelEvent));
	eventManagementMenu.addCommand(Command("Query - Most Watched", command_mostWatched));
	eventManagementMenu.addCommand(Command("Query - Below 10% watchers", command_belowWatchers));

	reportsMenu.addCommand(Command("Reservations List", command_reservationsList));
	reportsMenu.addCommand(Command("Bought Tickets", command_boughtTickets));
}

void runUI(EventService* eventService, HallService* hallService) {
	es = eventService;
	hs = hallService;
	load();
	init();
	mainMenu.navigate();
	save();
}
