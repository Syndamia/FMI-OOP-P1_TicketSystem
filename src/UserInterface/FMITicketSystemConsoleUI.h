#ifndef HEADER_FMITICKETSYSTEMCONSOLEUI
#define HEADER_FMITICKETSYSTEMCONSOLEUI

/*! \file FMITicketSystemConsoleUI.h
 *  \brief Stores declaration of runUI function
 */

#include "../Services/EventService.h"
#include "../Services/HallService.h"

//! Runs the console interface for the ticket system
void runUI(EventService* eventService, HallService* hallService);

#endif
