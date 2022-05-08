/*! \mainpage FMI Tickets System
 *
 * GitHub source code repository: <a href="https://github.com/Syndamia/FMI-OOP-P1_TicketSystem">Syndamia/FMI-OOP-P1_TicketSystem</a> 
 */

/*! \file main.cpp
 *  \brief Entry point for application
 *
 * Contains the main() function.
 */

#include "Services/EventService.h"
#include "Services/HallService.h"
#include "Models/Hall.h"
#include "UserInterface/VenueConsoleUI.h"

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
