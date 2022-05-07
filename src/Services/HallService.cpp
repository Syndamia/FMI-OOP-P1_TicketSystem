#include "HallService.h"

HallService::HallService(const Hall* halls, unsigned hallCount) {
	this->halls = OrderedList<Hall>(halls, hallCount);
}
