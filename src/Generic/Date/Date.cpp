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

Date::Date(const char* str) {
	while (*str == ' ' && *str != '\0') str++;
	set_day(atoi(str));
	str += 2;
	while (*str == ' ' && *str != '\0') str++;
	set_month(atoi(str));
	str += 2;
	while (*str == ' ' && *str != '\0') str++;
	set_year(atoi(str));
}

Date::Date(unsigned short day, unsigned short month, unsigned short year) {
	this->day = this->month = this->year = 0;
	set_day(day);
	set_month(month);
	set_year(year);
}

unsigned short Date::get_day() const {
	return day;
}

bool Date::set_day(unsigned short newDay) {
	if (newDay == 0 || newDay > daysInMonth())
		return false;
	day = newDay;
	return true;
}

unsigned short Date::get_month() const {
	return month;
}
bool Date::set_month(unsigned short newMonth) {
	if (newMonth == 0 || newMonth > 12)
		return false;
	month = newMonth;
	return true;
}

unsigned short Date::get_year() const {
	return year;
}
bool Date::set_year(unsigned short newYear) {
	year = newYear;
	return true;
}

int digitToChar(unsigned digit) {
	if (digit <= 9)
		return '0' + digit;
	return ' ';
}

String Date::createString() const {
	String out;
	return ((((out += day) += ".") += month) += ".") += year;
}

void Date::read(std::istream& istr) {
	istr.read((char*)&day, sizeof(day));
	istr.read((char*)&month, sizeof(month));
	istr.read((char*)&year, sizeof(year));
}

void Date::write(std::ostream& ostr) {
	ostr.write((char*)&day, sizeof(day));
	ostr.write((char*)&month, sizeof(month));
	ostr.write((char*)&year, sizeof(year));
}

int Date::compare(const Date& other) const {
	if (year < other.year || month < other.month || day < other.day)
		return -1;
	return year > other.year || month > other.month || day > other.day;
}


/* Outside of class */

std::istream& operator>>(std::istream& istr, Date& dt) {
	unsigned short d, M, y;
	istr >> d >> M >> y;
	dt = Date(d, M, y);
	return istr;
}

std::ostream& operator<<(std::ostream& ostr, const Date& dt) {
	ostr << dt.get_day() << "." << dt.get_month() << "." << dt.get_year();
	return ostr;
}
