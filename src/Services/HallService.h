#ifndef HEADER_SERVICES_HALLSERVICE
#define HEADER_SERVICES_HALLSERVICE

/*! \file HallService.h
 *  \brief Stores the declaration of class HallService
 */

#include "../Generic/List/OrderedList.hpp"
#include "../Models/Hall.h"
#include "StatusCode.h"

/*! \brief Each HallService stores all halls
 */
class HallService {
	OrderedList<Hall> halls;

public:
	//! Copies halls from parameters
	HallService(const Hall* halls, unsigned hallCount);

	//! Returns a constant reference to halls
	const OrderedList<Hall>& get_halls() const;

	//! Loads Halls to a database file
	StatusCode load();
	//! Saves Halls to a database file
	StatusCode save();
};

#endif
