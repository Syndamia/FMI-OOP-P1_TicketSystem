#include "VenueConsoleUI.h"
#include "../Generic/List/OrderedList.hpp"
#include "../Generic/String/String.h"
#include "../Generic/Date/Date.h"
#include "../Generic/ConsoleInterface/Menu.h"
#include "../Generic/ConsoleInterface/Toolbox.hpp"
#include "../Services/StatusCode.h"
#include "../Models/Reservation.h"

EventService* es;
HallService* hs;

Menu mainMenu("FMI Ticket System", true, false), ticketManagementMenu("Ticket management", false, true), eventManagementMenu("Event management", false, true), reportsMenu("Report management", false, true);

void handleStatusCode(StatusCode sc, Menu menu) {
	switch (sc) {
		case Success:
			menu.registerSuccess("Success!"); break;
		case W_TicketHadNotBeenReserved:
			menu.registerWarning("Ticket hadn't been reserved. Nothing changed."); break;
		case E_EventDoesNotExist: 
			menu.registerError("Event doesn't exist!"); break;
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

	if (!hs->hallExists()) {
		handleStatusCode(E_HallDoesntExist, ticketManagementMenu);
		return;
	}

	OrderedList<Ticket> tickets = es->queryTickets(name, date);
	OrderedList<Reservation> reservations = es->queryReservations(name, date);

	unsigned tableSize = hall->get_rowCount() * hall->get_seatsPerRow();
	char tableData[tableSize + 1];

	for (unsigned ind = 0, row = 1; row <= hall->get_rowCount(); row++) {
		for (unsigned seat = 1; seat <= hall->get_seatsPerRow(); seat++, ind++) {
			if (tickets.contain(Ticket(row, seat)))
				tableData[ind] = 'B';
			else if (reservations.contain(Ticket(row, seat)))
				tableData[ind] = 'R';
			else
				tableData[ind] = ' ';
		}
	}

	tableData[tableSize] = '\0';
	table(1, hall->get_seatsPerRow(), tableData);

	char tmp;
	inputLineBox("[Press enter to continue]", &tmp, 1);
}

void command_reserveTicket() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	Ticket tic;
	inputSubBox("Enter row and seat: ", &tic);
	char password[PASSWORD_LEN];
	inputSubBox("Enter password [Max 8 characters]: ", &password);
	char note[NOTE_LEN];
	inputSubBox("Enter note [Max 32 characters]: ", &note);

	handleStatusCode(v->get_es().reserveTicket(name, date, password, note, tic), ticketManagementMenu);
}

void command_cancelReservation() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	Ticket tic;
	inputSubBox("Enter row and seat: ", &tic);

	handleStatusCode(v->get_es().cancelTicketReservation(name, date, tic), ticketManagementMenu);
}

void command_buyTicket() {
	bool reserved;
	inputSubBox("Is ticket reserved? [0/1]: ", &reserved);
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	Ticket tic;
	inputSubBox("Enter row and seat: ", &tic);

	if (reserved) {
		char pass[PASSWORD_LEN];
		inputLineSubBox("Enter reservation password: ", pass, PASSWORD_LEN);
		handleStatusCode(v->get_es().buyTicket(name, date, tic, pass), ticketManagementMenu);
	}
	else
		handleStatusCode(v->get_es().buyTicket(name, date, tic), ticketManagementMenu);
}

void submenu_ticketManagement() {
	ticketManagementMenu.navigate();
}

/* Event Management */

void command_createEvent() {
	unsigned hallIndex;
	inputSubBox("Enter hall index: ", &hallIndex);
	if (!v->hallExists(hallIndex)) {
		eventManagementMenu.registerError("Invalid hall index!");
		return;
	}
	
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);
	
	handleStatusCode(v->get_es().createEvent(&v->getHall(hallIndex), name, date), eventManagementMenu);
}

void command_cancelEvent() {
	char name[MAX_LINE_WIDTH];
	inputLineSubBox("Enter event name: ", name, MAX_LINE_WIDTH);
	Date date;
	inputSubBox("Enter event date: ", &date);

	handleStatusCode(v->get_es().cancelEvent(name, date), eventManagementMenu);
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

}

void command_boughtTickets() {

}

void submenu_reportManagement() {
	reportsMenu.navigate();
}

/* Main */


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
	init();
	mainMenu.navigate();
}
