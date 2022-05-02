#include "Event.h"

Event::Event() : Event(nullptr, "", "") {}

Event::Event(const Hall* hall, String name, DateTime time) {
	this->hall = hall;
}
