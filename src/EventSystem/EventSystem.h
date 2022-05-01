#ifndef HEADER_EVENTSYSTEM
#define HEADER_EVENTSYSTEM

#include "../List/List.h"

#include "Event.h"

class EventSystem {
	List<Event> events;
	unsigned indSoonestUpcoming;

public:
	EventSystem(const Event* events, unsigned eventCount);
};

#endif
