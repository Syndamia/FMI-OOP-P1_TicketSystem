#include "EventSystem.h"

/* Private */

void EventSystem::updateSoonestUpcoming() {
	
}

/* Public */

EventSystem::EventSystem() {
	events = OrderedList<Event>();
	indSoonestUpcoming = 0;
}

EventSystem::EventSystem(const Event* events, unsigned eventCount) {
	this->events = OrderedList<Event>(events, eventCount);
	indSoonestUpcoming = 0;
	updateSoonestUpcoming();
}

StatusCode EventSystem::createEvent(const Hall* hall, String name, DateTime time) {
	events.insert(Event(hall, name, time));
	return Success;
}
