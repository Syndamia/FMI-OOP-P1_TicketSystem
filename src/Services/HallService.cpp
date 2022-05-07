#include "HallService.h"

HallService::HallService(const Hall* halls, unsigned hallCount) {
	this->halls = OrderedList<Hall>(halls, hallCount);
}

const OrderedList<Hall>& HallService::get_halls() const {
	return halls;
}
