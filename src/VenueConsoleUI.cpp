#include "VenueConsoleUI.h"
#include "String/String.h"
#include "DateTime/DateTime.h"
#include "EventSystem/StatusCodes.h"
#include "EventSystem/EventSystem.h"
#include "ConsoleInterface/Menu.h"
#include "ConsoleInterface/Toolbox.hpp"

Venue* v;

void handleStatusCode(StatusCode sc) {
	switch (sc) {
		case Success: printSuccess("Success!"); break;
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
	DateTime dt;
	inputBox("Enter event date and time: ", &dt);
	
	handleStatusCode(v->get_es().createEvent(&v->get_halls()[hallIndex], name, dt));
}

/* Ticket Management */

void command_freeSeats() {

}

void command_reserveTicket() {

}

void command_cancelReservation() {

}

void command_buyTicket() {

}

void submenu_ticketManagement() {
	
}

/* Event Management */

void submenu_eventManagement() {

}

/* Report Management */

void submenu_reportManagement() {

}

/* Main */

Menu mainMenu, ticketManagementMenu, eventManagementMenu, reportsMenu;

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
