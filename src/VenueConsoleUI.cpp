#include "VenueConsoleUI.h"
#include "String/String.h"
#include "DateTime/DateTime.h"
#include "EventSystem/StatusCodes.h"
#include "ConsoleInterface/Menu.h"
#include "ConsoleInterface/Toolbox.hpp"

Venue v;

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
	if (!v.hallExists(hallIndex)) {
		printError("Invalid hall index!");
		return;
	}
	
	char name[MAX_LINE_WIDTH];
	inputLineBox("Enter event name: ", name, MAX_LINE_WIDTH);
	DateTime dt;
	inputBox("Enter event date and time: ", &dt);
	
	handleStatusCode(v.get_es().createEvent(&v.get_halls()[hallIndex], name, dt));
}

void runUI(Venue& venue) {
	v = venue;
}
