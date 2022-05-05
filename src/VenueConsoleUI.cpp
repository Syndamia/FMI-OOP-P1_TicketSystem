#include "VenueConsoleUI.h"
#include "String/String.h"
#include "ConsoleInterface/Menu.h"
#include "ConsoleInterface/Toolbox.hpp"

Venue v;

void command_newEvent() {
	char name[MAX_LINE_WIDTH];
	inputLineBox("Enter event name: ", name, MAX_LINE_WIDTH);
	
	v.es.createEvent();
}

void runUI(Venue& venue) {
	v = venue;
}
