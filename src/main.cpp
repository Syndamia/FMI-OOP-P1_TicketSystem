#include "Services/EventService.h"
#include "Services/HallService.h"
#include "Models/Hall.h"
#include "UserInterface/VenueConsoleUI.h"

int main() {
	Hall myVenueHalls[] = { Hall(1, 20, 30), Hall(2, 15, 15), Hall(3, 10, 20) };

	HallService hs(myVenueHalls, 3);
	EventService es(&hs);
	
	runUI(&es, &hs);
}
