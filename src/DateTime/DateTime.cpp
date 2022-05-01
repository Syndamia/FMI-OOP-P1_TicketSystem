#include "DateTime.h"

/* Private */

bool DateTime::isLeapYear() {
	return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
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
	
}

unsigned short get_month();
bool set_month(unsigned short newMonth);

unsigned short DateTime::get_year() {
	return year;
}
bool DateTime::set_year(unsigned short newYear) {
	year = newYear;
	return true;
}
