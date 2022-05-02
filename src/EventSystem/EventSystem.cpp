#include "EventSystem.h"

/* Private */

void EventSystem::updateSoonestUpcoming() {
	
}

/* Public */

EventSystem::EventSystem(const Event* events, unsigned eventCount) {
	this->events = OrderedList<Event>(events, eventCount);
	indSoonestUpcoming = 0;
	updateSoonestUpcoming();
}
