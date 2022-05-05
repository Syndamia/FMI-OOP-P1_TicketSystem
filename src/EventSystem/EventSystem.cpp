#include "EventSystem.h"
#include "StatusCodes.h"

/* Private */

void EventSystem::updateSoonestUpcoming() {
	
}

unsigned EventSystem::indexOfEvent(const Date& dt) {
	for (unsigned i = indSoonestUpcoming; i < events.get_count(); i++) {
		if (events[i].get_date().compare(dt) == 0)
			return i;
	}
	return events.get_count();
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
	if (indexOfEvent(date) < events.get_count())
		return E_EventWillOverlap;

	events.insert(Event(hall, name, date));
	return Success;
}

List<Ticket> EventSystem::queryFreeTickets(const char* name, const Date& dt) {
	unsigned ind = indexOfEvent(name, dt);

	if (ind == events.get_count())
		return List<Ticket>();

	List<Ticket> freeTickets = List<Ticket>();

	unsigned nextIndT = 0, nextIndR = 0;
	for (unsigned r = 1; r <= events[ind].get_hall().get_rowCount(); r++) {
		for (unsigned s = 1; s <= events[ind].get_hall().get_seatsPerRow(); s++) {
			// TODO: finish
		}
	}

	return freeTickets;
}
