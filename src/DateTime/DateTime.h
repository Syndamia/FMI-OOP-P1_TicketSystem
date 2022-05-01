#ifndef HEADER_DATETIME
#define HEADER_DATETIME

class DateTime {
	unsigned short hour;
	unsigned short minute;
	unsigned short day;
	unsigned short month;
	unsigned short year;

	bool isLeapYear();

public:
	DateTime(unsigned short hour, unsigned short minute, unsigned short day, unsigned short month, unsigned short year);
	int compare(const DateTime& other);

	unsigned short get_hour();
	bool set_hour(unsigned short newHour);

	unsigned short get_minute();
	bool set_minute(unsigned short newMinute);

	unsigned short get_day();
	bool set_day(unsigned short newDay);

	unsigned short get_month();
	bool set_month(unsigned short newMonth);

	unsigned short get_year();
	bool set_year(unsigned short newYear);
};

#endif
