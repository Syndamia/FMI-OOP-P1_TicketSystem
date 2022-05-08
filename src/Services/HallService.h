#ifndef HEADER_SERVICES_HALLSERVICE
#define HEADER_SERVICES_HALLSERVICE

#include "../Generic/List/OrderedList.hpp"
#include "../Models/Hall.h"
#include "StatusCode.h"

class HallService {
	OrderedList<Hall> halls;

public:
	HallService(const Hall* halls, unsigned hallCount);

	const OrderedList<Hall>& get_halls() const;

	StatusCode load();
	StatusCode save();
};

#endif
