#include "DateTime.h"

/* Private */

bool DateTime::isLeapYear() {
	// Implements https://en.wikipedia.org/wiki/Leap_year#Gregorian_calendar
	return year % 400 == 0 || year % 100 != 0 || year % 4 == 0;
}

unsigned short DateTime::daysInMonth() {
	if (month == 2)
		return 28 + isLeapYear();
	if (month <= 7)
		return 30 + month % 2;
	return 31 - month % 2;
}

/* Public */

DateTime::DateTime(unsigned short hour, unsigned short minute, unsigned short day, unsigned short month, unsigned short year) {
	this->hour = hour;
	this->minute = minute;
	this->day = day;
	this->month = month;
	this->year = year;
}

int DateTime::compare(const DateTime& other) {
	if (year < other.year || month < other.month || day < other.day || hour < other.hour || minute < other.minute)
		return -1;
	return year > other.year || month > other.month || day > other.day || hour > other.hour || minute > other.minute;
}


unsigned short DateTime::get_hour() {
	return hour;
}
bool DateTime::set_hour(unsigned short newHour) {
	if (newHour > 23)
		return false;
	hour = newHour;
	return true;
}

unsigned short DateTime::get_minute() {
	return minute;
}
bool DateTime::set_minute(unsigned short newMinute) {
	if (newMinute > 59)
		return false;
	minute = newMinute;
	return true;
}

unsigned short DateTime::get_day() {
	return day;
}
bool DateTime::set_day(unsigned short newDay) {
	if (newDay == 0 || newDay > daysInMonth())
		return false;
	day = newDay;
	return true;
}

unsigned short DateTime::get_month() {
	return month;
}
bool DateTime::set_month(unsigned short newMonth) {
	if (newMonth == 0 || newMonth > 12)
		return false;
	month = newMonth;
	return true;
}

unsigned short DateTime::get_year() {
	return year;
}
bool DateTime::set_year(unsigned short newYear) {
	year = newYear;
	return true;
}

/* Outside of class */

std::istream& operator>>(std::istream& istr, DateTime& dt) {
	unsigned short h, m, d, M, y;
	istr >> h >> m >> d >> M >> y;
	dt = DateTime(h, m, d, M, y);
	return istr;
}

std::ostream& operator<<(std::ostream& ostr, const DateTime& dt);
