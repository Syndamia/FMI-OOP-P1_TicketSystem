#ifndef HEADER_SERVICE_HALLSERVICE
#define HEADER_SERVICE_HALLSERVICE

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
