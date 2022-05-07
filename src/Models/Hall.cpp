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

void Hall::read(std::istream& istr) {
	istr.read((char*)&number, sizeof(number));
	istr.read((char*)&rows, sizeof(rows));
	istr.read((char*)&seatsPerRow, sizeof(seatsPerRow));
}

void Hall::write(std::ostream& ostr) {
	istr.write((char*)&number, sizeof(number));
	istr.write((char*)&rows, sizeof(rows));
	istr.write((char*)&seatsPerRow, sizeof(seatsPerRow));
}

int Hall::compare(const Hall& other) const {
	return (number > other.get_number()) - (number < other.get_number());
}
