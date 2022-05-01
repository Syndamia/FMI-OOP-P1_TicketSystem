#ifndef HEADER_VENUE
#define HEADER_VENUE

#include "List/List.h"
#include "Hall.h"
#include "EventSystem/EventSystem.h"

class Venue {
	List<Hall> halls;
	EventSystem es;

public:
	Venue(const Hall* halls, unsigned hallCount, const EventSystem& es);

	const List<Hall> get_halls() const;
	const EventSystem get_es() const;
};

#endif
