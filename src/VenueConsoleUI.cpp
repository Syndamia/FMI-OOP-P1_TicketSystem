#include "VenueConsoleUI.h"
#include "String/String.h"
#include "Date/Date.h"
#include "EventSystem/StatusCodes.h"
#include "EventSystem/Reservation.h"
#include "EventSystem/EventSystem.h"
#include "ConsoleInterface/Menu.h"
#include "ConsoleInterface/Toolbox.hpp"

Venue* v;
Menu mainMenu("FMI Ticket System"), ticketManagementMenu("Ticket management"), eventManagementMenu("Event management"), reportsMenu("Report management");

void handleStatusCode(StatusCode sc, Menu menu) {
	switch (sc) {
		case Success:
			menu.registerSuccess("Success!"); break;
		case E_EventDoesNotExist: 
			menu.registerError("Event doesn't exist!"); break;
		case E_TicketAlreadyBought:
			menu.registerError("Ticket was already bought!"); break;
		case E_TicketAlreadyReserved:
			menu.registerError("Ticket was already reserved!"); break;
		default: break;
	}
}

void command_newEvent() {
	printTitle("Creating new event");

	unsigned hallIndex;
	inputBox("Enter hall index: ", &hallIndex);
	if (!v->hallExists(hallIndex)) {
		printError("Invalid hall index!");
		return;
	}
	
	char name[MAX_LINE_WIDTH];
	inputLineBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputBox("Enter event date and time: ", &date);
	
	handleStatusCode(v->get_es().createEvent(&v->get_halls()[hallIndex], name, date), eventManagementMenu);
}

/* Ticket Management */

void command_freeSeats() {
	char name[MAX_LINE_WIDTH];
	inputLineBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputBox("Enter event date: ", &date);
	print("Number of free seats: ");
	// printLine(v->get_es().queryFreeSeats(name, date));
}

void command_reserveTicket() {
	char name[MAX_LINE_WIDTH];
	inputLineBox("Enter event name: ", name, MAX_LINE_WIDTH);
	std::cin.ignore();
	Date date;
	inputBox("Enter event date: ", &date);
	char password[PASSWORD_LEN];
	inputBox("Enter password [Max 8 characters]: ", &password);
	char note[NOTE_LEN];
	inputBox("Enter note [Max 32 characters]: ", &note);
	unsigned row;
	inputBox("Enter row: ", &row);
	unsigned seat;
	inputBox("Enter seat: ", &seat);

	handleStatusCode(v->get_es().reserveTicket(name, date, password, note, row, seat), ticketManagementMenu);
}

void command_cancelReservation() {

}

void command_buyTicket() {

}

void submenu_ticketManagement() {
	ticketManagementMenu.navigate();
}

/* Event Management */

void submenu_eventManagement() {

}

/* Report Management */

void submenu_reportManagement() {

}

/* Main */


void init() {
	mainMenu.addCommand(Command("Ticket Management", submenu_ticketManagement));
	mainMenu.addCommand(Command("Event Management", submenu_eventManagement));
	mainMenu.addCommand(Command("Report Management", submenu_reportManagement));

	ticketManagementMenu.addCommand(Command("Count of Free Seats", command_freeSeats));
	ticketManagementMenu.addCommand(Command("Reserve Ticket", command_reserveTicket));
	ticketManagementMenu.addCommand(Command("Cancel Ticket Reservation", command_cancelReservation));
	ticketManagementMenu.addCommand(Command("Buy Ticket", command_buyTicket));
}

void runUI(Venue& venue) {
	v = &venue;
	init();
	mainMenu.navigate();
}
