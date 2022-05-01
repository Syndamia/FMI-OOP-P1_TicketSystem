#include "DateTime.h"

DateTime::DateTime(unsigned char hour, unsigned char minute, unsigned char day, unsigned char month, unsigned short year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

DateTime::compare(const DateTime& other) {
	
}
