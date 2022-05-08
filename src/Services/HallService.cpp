#include "HallService.h"
#include <fstream>

HallService::HallService(const Hall* halls, unsigned hallCount) {
	this->halls = OrderedList<Hall>(halls, hallCount);
}

const OrderedList<Hall>& HallService::get_halls() const {
	return halls;
}

/*!
 * Looks for file named "hallsDatabse.fmits", which is just a binary file, and then reads it with the "read" function in events List.
 *
 * \return E_FileCouldNotBeOpened \b if The files couldn't be opened/Doesn't exist
 * \return Success \b otherwise
 */
StatusCode HallService::load() {
	std::ifstream inFile("hallsDatabase.fmits");
	if (!inFile.is_open())
		return E_FileCouldNotBeOpened;

	halls.read(inFile);
	inFile.close();
	return Success;
}

/*!
 * Looks for file named "hallsDatabse.fmits", which is just a binary file, and then writes to it with the "write" function in events List.
 *
 * \return E_FileCouldNotBeOpened \b if The files couldn't be opened
 * \return Success \b otherwise
 */
StatusCode HallService::save() {
	std::ofstream outFile("hallsDatabase.fmits");
	if (!outFile.is_open())
		return E_FileCouldNotBeOpened;

	halls.write(outFile);
	outFile.close();
	return Success;
}
