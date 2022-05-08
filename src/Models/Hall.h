#ifndef HEADER_MODEL_HALL
#define HEADER_MODEL_HALL

/*! \file Hall.h
 *  \brief Stores the declaration of class Hall
 */

#include <istream>
#include <ostream>

/*! \brief Each hall contains a number, rows and seats per row
 */
class Hall {
	int number;
	unsigned rows;
	unsigned seatsPerRow;

public:
	//! Sets values to 0
	Hall();
	//! Sets values, except number, to 0
	Hall(int number);
	//! Sets values
	Hall(int number, unsigned rows, unsigned seatsPerRow);

	//! Returns a Hall's number
	int get_number() const;
	//! Returns a Hall's row count
	unsigned get_rows() const;
	//! Return a Hall's seats per row count
	unsigned get_seatsPerRow() const;

	//! Reads Hall from stream
	void read(std::istream& istr);
	//! Writes Hall to steam
	void write(std::ostream& ostr) const;
	//! Compare two Halls
	int compare(const Hall& other) const;

};

//! Reads Hall from stream with >> operator
std::istream& operator>>(std::istream& istr, Hall& hall);
//! Writes Hall to stream with << operator
std::ostream& operator<<(std::ostream& ostr, const Hall& hall);

#endif
