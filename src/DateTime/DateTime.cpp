#include "DateTime.h"

DateTime::DateTime(unsigned char hour, unsigned char minute, unsigned char day, unsigned char month, unsigned short year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int DateTime::compare(const DateTime& other) {
	if (year < other.year || month < other.month || day < other.day || hour < other.hour || minute < other.minute)
		return -1;
	return year > other.year && month > other.month && day > other.day && hour > other.hour && minute > other.minute;
}
