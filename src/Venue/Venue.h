#ifndef HEADER_VENUE
#define HEADER_VENUE

#include "../List/List.hpp"
#include "Hall.h"
#include "../EventSystem/EventSystem.h"

class Venue {
	List<Hall> halls;
	EventSystem es;

public:
	Venue(const Hall* halls, unsigned hallCount, const EventSystem& es);

	bool hallExists(const Hall& hall) const;

	const List<Hall>& get_halls() const;
	const EventSystem& get_es() const;
};

#endif
