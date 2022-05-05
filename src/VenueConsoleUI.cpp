#include "VenueConsoleUI.h"
#include "String/String.h"
#include "ConsoleInterface/Menu.h"
#include "ConsoleInterface/Toolbox.hpp"

Venue v;

void command_newEvent() {
	String name;
	inputStrBox(name, 1024, "Enter event name: ");
	v.es.createEvent();
}

void runUI(Venue& venue) {
	v = venue;
}
