#ifndef HEADER_HALL
#define HEADER_HALL

#include <istream>
#include <ostream>

class Hall {
	int number;
	unsigned rows;
	unsigned seatsPerRow;

public:
	Hall();
	Hall(int number);
	Hall(int number, unsigned rows, unsigned seatsPerRow);

	int get_number() const;
	unsigned get_rows() const;
	unsigned get_seatsPerRow() const;

	void read(std::istream& istr);
	void write(std::ostream& ostr) const;
	int compare(const Hall& other) const;

};

std::istream& operator>>(std::istream& istr, Hall& hall);
std::ostream& operator<<(std::ostream& ostr, const Hall& hall);

#endif
