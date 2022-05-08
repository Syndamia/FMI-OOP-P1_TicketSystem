#ifndef HEADER_VENUECONSOLEUI
#define HEADER_VENUECONSOLEUI

/*! \file VenueConsoleUI.h
 *  \brief Stores declaration of runUI function
 */

#include "../Services/EventService.h"
#include "../Services/HallService.h"

//! Runs the console interface for the ticket system
void runUI(EventService* eventService, HallService* hallService);

#endif
