#include "Hall.h"

Hall::Hall() : Hall(0, 0, 0) {}

Hall::Hall(int number, unsigned rows, unsigned seatsPerRow) {
	this->number = number;
	this->rows = rows;
	this->seatsPerRow = seatsPerRow;
}

int Hall::get_number() const {
	return number;
}
void Hall::set_number(int number) {
	this->number = number;
}

unsigned Hall::get_rows() const {
	return rows;
}
void Hall::set_rows(unsigned rows) {
	this->rows = rows;
}

unsigned Hall::get_seatsPerRow() const {
	return seatsPerRow;
}
void Hall::set_seatsPerRow(unsigned seatsPerRow) {
	this->seatsPerRow = seatsPerRow;
}

int Hall::compare(const Hall& other) {
	return (number > other.get_number()) - (number < other.get_number());
}
