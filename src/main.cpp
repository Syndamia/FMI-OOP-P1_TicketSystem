#include "VenueConsoleUI.h"
#include "Venue/Venue.h"
#include "Venue/Hall.h"

int main() {
	Hall myVenueHalls[] = { Hall(1, 20, 30), Hall(2, 15, 15), Hall(3, 10, 20) };
	
	Venue myVenue(myVenueHalls, 3, EventSystem());
	runUI(myVenue);
}
