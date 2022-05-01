#ifndef HEADER_DATETIME
#define HEADER_DATETIME

#include <istream>
#include <ostream>

class DateTime {
	unsigned short hour;
	unsigned short minute;
	unsigned short day;
	unsigned short month;
	unsigned short year;

	bool isLeapYear();
	unsigned short daysInMonth();

public:
	DateTime(unsigned short hour, unsigned short minute, unsigned short day, unsigned short month, unsigned short year);
	int compare(const DateTime& other) const;

	unsigned short get_hour() const;
	bool set_hour(unsigned short newHour);

	unsigned short get_minute() const;
	bool set_minute(unsigned short newMinute);

	unsigned short get_day() const;
	bool set_day(unsigned short newDay);

	unsigned short get_month() const;
	bool set_month(unsigned short newMonth);

	unsigned short get_year() const;
	bool set_year(unsigned short newYear);
};

std::istream& operator>>(std::istream& istr, DateTime& dt);
std::ostream& operator<<(std::ostream& ostr, const DateTime& dt);

#endif
