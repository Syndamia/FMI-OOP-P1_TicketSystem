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

StatusCode EventSystem::createEvent(const Hall* hall, String name, Date date) {
	events.insert(Event(hall, name, date));
	return Success;
}

unsigned EventSystem::queryFreeSeats(const char* name, const Date& dt) {
	unsigned index = events.get_count();
	for (unsigned i = indSoonestUpcoming; i < events.get_count(); i++) {
		if (events[i].get_date() == dt && events[i].get_name().compare(name) == 0) {
			index = i;
			break;
		}
	}

}
