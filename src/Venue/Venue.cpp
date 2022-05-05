#include "Venue.h"

Venue::Venue() : halls(), es() {}

Venue::Venue(const Hall* halls, unsigned hallCount) : es() {
	this->halls = List<Hall>(halls, hallCount);
}

Venue::Venue(const Hall* halls, unsigned hallCount, const EventSystem& es) {
	this->halls = List<Hall>(halls, hallCount);
	this->es = es;
}

bool Venue::hallExists(unsigned hallIndex) const {
	return hallIndex < halls.get_count();
}

bool Venue::hallExists(const Hall& hall) const {
	return this->halls.contain(hall);
}

const List<Hall>& Venue::get_halls() const {
	return this->halls;
}

EventSystem& Venue::get_es() {
	return this->es;
}
