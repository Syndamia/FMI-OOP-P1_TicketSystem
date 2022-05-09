/*! \file main.cpp
 *  \brief Entry point for application
 *
 * Contains the main() function.
 */

#include "Services/EventService.h"
#include "Services/HallService.h"
#include "Models/Hall.h"
#include "UserInterface/FMITicketSystemConsoleUI.h"

/*!  
 * Creates instances of HallService and EventService and
 * executes runUI() function.
 */
int main() {
	Hall myVenueHalls[] = { Hall(1, 20, 30), Hall(2, 15, 15), Hall(3, 10, 20) };

	HallService hs(myVenueHalls, 3);
	EventService es(&hs);
	
	runUI(&es, &hs);
}
