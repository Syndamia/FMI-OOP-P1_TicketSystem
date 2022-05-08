#include "Hall.h"

Hall::Hall() : Hall(0, 0, 0) {}

Hall::Hall(int number) : Hall(number, 0, 0) {}

Hall::Hall(int number, unsigned rows, unsigned seatsPerRow) {
	this->number = number;
	this->rows = rows;
	this->seatsPerRow = seatsPerRow;
}

int Hall::get_number() const {
	return number;
}
unsigned Hall::get_rows() const {
	return rows;
}

unsigned Hall::get_seatsPerRow() const {
	return seatsPerRow;
}

/*! \param istr An input stream
 *
 * Directly reads bytes from stream (calls read() function).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ifstream
 */
void Hall::read(std::istream& istr) {
	istr.read((char*)&number, sizeof(number));
	istr.read((char*)&rows, sizeof(rows));
	istr.read((char*)&seatsPerRow, sizeof(seatsPerRow));
}

/*! \param ostr An output stream
 *
 * Directly writes bytes to stream (calls write() function).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ofstream
 */
void Hall::write(std::ostream& ostr) const {
	ostr.write((char*)&number, sizeof(number));
	ostr.write((char*)&rows, sizeof(rows));
	ostr.write((char*)&seatsPerRow, sizeof(seatsPerRow));
}

/*! \return -1 if number < other.number, 1 if number > other.number, 0 if number == other.number
 */
int Hall::compare(const Hall& other) const {
	return (number > other.get_number()) - (number < other.get_number());
}

/*!
 * Uses the stream's >> operator to read and parse all internal values.
 *
 * \note Best used with std::cin or text std::ifstream
 */
std::istream& operator>>(std::istream& istr, Hall& hall) {
	int number;
	unsigned rows, seatsPerRow;
	istr >> number >> rows >> seatsPerRow;
	hall = Hall(number, rows, seatsPerRow);
	return istr;
}

/*!
 * Uses the stream's << operator to write all internal data.
 *   
 * \note Best used with std::cout or text std::ofstream
 */
std::ostream& operator<<(std::ostream& ostr, const Hall& hall) {
	return ostr << hall.get_number() << " " << hall.get_rows() << " "<< hall.get_seatsPerRow();
}
