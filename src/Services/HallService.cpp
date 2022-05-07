#include "HallService.h"
#include <fstream>

HallService::HallService(const Hall* halls, unsigned hallCount) {
	this->halls = OrderedList<Hall>(halls, hallCount);
}

const OrderedList<Hall>& HallService::get_halls() const {
	return halls;
}

StatusCode HallService::load() {
	std::ifstream inFile("hallsDatabase.fmits");
	if (!inFile.is_open())
		return E_FileCouldNotBeOpened;

	halls.read(inFile);
	inFile.close();
	return Success;
}

StatusCode HallService::save() {
	std::ofstream outFile("hallsDatabase.fmits");
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	halls.write(outFile);
	outFile.close();
	return Success;
}
