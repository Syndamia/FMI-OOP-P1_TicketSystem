#include "EventSystem.h"

/* Private */

void EventSystem::updateSoonestUpcoming() {
	
}

unsigned EventSystem::indexOfEvent(const char* name, const Date& dt) {
	for (unsigned i = indSoonestUpcoming; i < events.get_count(); i++) {
		if (events[i].get_date().compare(dt) == 0 && events[i].get_name().compare(name) == 0)
			return i;
	}
	return events.get_count();
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

List<Ticket> EventSystem::queryFreeTickets(const char* name, const Date& dt) {
	List<Ticket> freeTickets();
	unsigned ind = indexOfEvent(name, dt);

	if (ind < events[ind].get_count()) {
		
	}
	return freeTickets;
}
