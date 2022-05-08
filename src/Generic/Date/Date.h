#ifndef HEADER_DATE
#define HEADER_DATE

/*! \file Date.h
 *  \brief Stores the declaration of class Date
 */

#include <istream>
#include <ostream>
#include "../String/String.h"

/*! \brief Stores a day, month and year
 */
class Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;

	bool isLeapYear();
	unsigned short daysInMonth();

public:
	//! Sets date as 01 May 2022
	Date();
	//! Parses string
	Date(const char* str);
	//! Sets day, month and year
	Date(unsigned short day, unsigned short month, unsigned short year);

	//! Returns the day
	unsigned short get_day() const;
	//! Sets the day
	bool set_day(unsigned short day);
	//! Returns the month
	unsigned short get_month() const;
	//! Sets the month
	bool set_month(unsigned short month);
	//! Returns the year
	unsigned short get_year() const;
	//! Sets the year
	bool set_year(unsigned short year);

	//! Returns the date as a String object
	String createString() const;

	//! Reads date from stream
	void read(std::istream& istr);
	//! Writes date to stream
	void write(std::ostream& ostr);
	//! Compares two dates
	int compare(const Date& other) const;
};

//! Reads date from stream with >> operator
std::istream& operator>>(std::istream& istr, Date& dt);
//! Writes date to stream with << operator
std::ostream& operator<<(std::ostream& ostr, const Date& dt);

#endif
