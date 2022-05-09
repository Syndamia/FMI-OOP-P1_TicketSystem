#include "Date.h"
#include <cstring>

/* Private */

bool Date::isLeapYear() {
	// Implements https://en.wikipedia.org/wiki/Leap_year#Gregorian_calendar
	return year % 400 == 0 || year % 100 != 0 || year % 4 == 0;
}

unsigned short Date::daysInMonth() {
	if (month == 2)
		return 28 + isLeapYear();
	if (month <= 7)
		return 30 + month % 2;
	return 31 - month % 2;
}

/* Public */

Date::Date() : Date(01, 05, 2022) {}

/*! \param str C-style string
 *
 * Values are initialized with zeroes. Then it parses the string:
 *
 * Skips spaces, saves day with atoi, skips two characters,
 * skips spaces, saves month with atoi, skips two characters,
 * skips spaces, saves year with atoi.
 *
 * Values are validated with setters.
 * You should always have spaces between day, month and year and no non-numeric characters between them.
 *
 * \remark If there are non-numeric characters, as per atoi() spec, the appropriate property is zero.
 */
Date::Date(const char* str) : Date(0, 0, 0) {
	while (*str == ' ' && *str != '\0') str++;
	set_day(atoi(str));
	str += 2;
	while (*str == ' ' && *str != '\0') str++;
	set_month(atoi(str));
	str += 2;
	while (*str == ' ' && *str != '\0') str++;
	set_year(atoi(str));
}

/*!
 * Initializes values with zeroes and then uses setters to save the function arguments.
 */
Date::Date(unsigned short day, unsigned short month, unsigned short year) {
	this->day = this->month = this->year = 0;
	set_day(day);
	set_month(month);
	set_year(year);
}

unsigned short Date::get_day() const {
	return day;
}

/*! \return Whether newDay was saved or not
 *
 * If newDay is equal to 0, or is more than the appropriate days in the month, the day isn't set.
 */
bool Date::set_day(unsigned short newDay) {
	if (newDay == 0 || newDay > daysInMonth())
		return false;
	day = newDay;
	return true;
}

unsigned short Date::get_month() const {
	return month;
}

/*! \return Whether newMonth was saved or not
 *
 * If newMonth is equal to 0 or is more than 12, the month isn't set.
 */
bool Date::set_month(unsigned short newMonth) {
	if (newMonth == 0 || newMonth > 12)
		return false;
	month = newMonth;
	return true;
}

unsigned short Date::get_year() const {
	return year;
}

/*! \return Whether year was saved or not
 *
 * Year isn't set when newYear is zero
 */
bool Date::set_year(unsigned short newYear) {
	if (newYear == 0)
		return false;
	year = newYear;
	return true;
}

int digitToChar(unsigned digit) {
	if (digit <= 9)
		return '0' + digit;
	return ' ';
}

/*! \return String object in the format "day.month.year"
 *
 * \note Currently there isn't any way to change the formatting
 */
String Date::createString() const {
	String out;
	return ((((out += day) += ".") += month) += ".") += year;
}

/*! \param istr An input stream
 *
 * Directly reads bytes from stream (calls read() function).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ifstream
 */
void Date::read(std::istream& istr) {
	istr.read((char*)&day, sizeof(day));
	istr.read((char*)&month, sizeof(month));
	istr.read((char*)&year, sizeof(year));
}

/*! \param ostr An output stream
 *
 * Directly writes bytes to stream (calls write() function).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ofstream
 */
void Date::write(std::ostream& ostr) {
	ostr.write((char*)&day, sizeof(day));
	ostr.write((char*)&month, sizeof(month));
	ostr.write((char*)&year, sizeof(year));
}

/*! \returns -1 if this < other, 1 if this > other, 0 if this == other
 */
int Date::compare(const Date& other) const {
	if (year < other.year || month < other.month || day < other.day)
		return -1;
	return year > other.year || month > other.month || day > other.day;
}


/* Outside of class */

/*!
 * Uses the stream's >> operator to read and parse the day, month and year.
 *
 * \note Best used with std::cin or text std::ifstream
 */
std::istream& operator>>(std::istream& istr, Date& dt) {
	unsigned short d, M, y;
	istr >> d >> M >> y;
	dt = Date(d, M, y);
	return istr;
}

/*!
 * Uses the stream's << operator to write the date in the format "day.month.year"
 *
 * \note Best used with std::cout or text std::ofstream
 */
std::ostream& operator<<(std::ostream& ostr, const Date& dt) {
	ostr << dt.get_day() << "." << dt.get_month() << "." << dt.get_year();
	return ostr;
}
