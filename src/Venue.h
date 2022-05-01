#ifndef HEADER_VENUE
#define HEADER_VENUE

#include "List/List.h"
#include "Hall.h"
#include "EventSystem/EventSystem.h"

class Venue {
	List<Hall> halls;
	EventSystem es;
};

#endif
