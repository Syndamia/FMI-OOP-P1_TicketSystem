#include "Hall.h"

Hall::Hall() : Hall(0, 0, 0) {}

Hall::Hall(int index, unsigned rowCount, unsigned seatsPerRow) {
	this->index = index;
	this->rowCount = rowCount;
	this->seatsPerRow = seatsPerRow;
}

int Hall::get_index() const {
	return index;
}
void Hall::set_index(int index) {
	this->index = index;
}

unsigned Hall::get_rowCount() const {
	return rowCount;
}
void Hall::set_rowCount(unsigned rowCount) {
	this->rowCount = rowCount;
}

unsigned Hall::get_seatsPerRow() const {
	return seatsPerRow;
}
void Hall::set_seatsPerRow(unsigned seatsPerRow) {
	this->seatsPerRow = seatsPerRow;
}
