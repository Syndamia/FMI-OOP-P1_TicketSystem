#ifndef HEADER_DATETIME
#define HEADER_DATETIME

class DateTime {
	unsigned hour;
	unsigned minute;
	unsigned day;
	unsigned month;
	unsigned year;

public:
	DateTime(unsigned hour, unsigned minute, unsigned day, unsigned month, unsigned year);
	int compare(const DateTime& other);
};

#endif
