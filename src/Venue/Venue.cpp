#include "Venue.h"

Venue::Venue(const Hall* halls, unsigned hallCount, const EventSystem& es) {
	this->halls = List<Hall>(halls, hallCount);
	this->es = es;
}
