#include "VenueConsoleUI.h"
#include "String/String.h"
#include "ConsoleInterface/Menu.h"
#include "ConsoleInterface/Toolbox.hpp"

Venue v;

void command_newEvent() {
	
	v.es.createEvent();
}

void runUI(Venue& venue) {
	v = venue;
}
