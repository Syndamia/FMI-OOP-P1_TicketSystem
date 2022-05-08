#ifndef HEADER_DATETIME
#define HEADER_DATETIME

#include <istream>
#include <ostream>

class Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;

	bool isLeapYear();
	unsigned short daysInMonth();

public:
	Date();
	Date(const char* str);
	Date(unsigned short day, unsigned short month, unsigned short year);

	unsigned short get_day() const;
	bool set_day(unsigned short day);
	unsigned short get_month() const;
	bool set_month(unsigned short month);
	unsigned short get_year() const;
	bool set_year(unsigned short year);

	void read(std::istream& istr);
	void write(std::ostream& ostr);
	int compare(const Date& other) const;
};

std::istream& operator>>(std::istream& istr, Date& dt);
std::ostream& operator<<(std::ostream& ostr, const Date& dt);

#endif
