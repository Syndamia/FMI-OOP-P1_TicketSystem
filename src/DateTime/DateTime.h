#ifndef HEADER_DATETIME
#define HEADER_DATETIME

class DateTime {
	unsigned char hour;
	unsigned char minute;
	unsigned char day;
	unsigned char month;
	unsigned short year;

public:
	DateTime(unsigned char hour, unsigned char minute, unsigned char day, unsigned char month, unsigned short year);
	int compare(const DateTime& other);
};

#endif
