#include "DateTime.h"

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
