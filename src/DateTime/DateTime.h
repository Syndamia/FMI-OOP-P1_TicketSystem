#ifndef HEADER_DATETIME
#define HEADER_DATETIME

class DateTime {
	unsigned short hour;
	unsigned short minute;
	unsigned short day;
	unsigned short month;
	unsigned short year;

public:
	DateTime(unsigned short hour, unsigned short minute, unsigned short day, unsigned short month, unsigned short year);
	int compare(const DateTime& other);

	unsigned short get_hour();
	unsigned short set_hour();
	unsigned short get_minute();
	unsigned short set_mintue();
	unsigned short get_day();
	unsigned short set_day();
	unsigned short get_month();
	unsigned short set_month();
	unsigned short get_year();
	unsigned short set_year();
};

#endif
