#include "Toolbox.hpp"

void clear() {
	// Clears console on Linux
	// Source: https://stackoverflow.com/a/52895729/12036073
	// std::cout << u8"\033[2J\033[1;1H"; 
}

int orderedListIndex = 1;

void resetOrderedList(int starter) {
	orderedListIndex = starter;
}

void titleBox(const char* title) {
	std::cout << std::endl << "=== " << title << " ===" << std::endl;
}

void subTitleBox(const char* title) {
	std::cout << std::endl << "--- " << title << " ---" << std::endl;
}

void successBox(const char* message) {
	std::cout << "<S> " << message << std::endl;
}

void warningBox(const char* message) {
	std::cout << "<W> " << message << std::endl;
}

void errorBox(const char* message) {
	std::cout << "<E> " << message << std::endl;
}

void __printTableColumnHeader(unsigned start, unsigned count) {
	for (unsigned i = 0; i < count - 1; i++, start++)
		std::cout << ":" << ((start < 100) ? " " : "") << start << ((start < 10) ? " " : "");
	std::cout << ":" << std::endl;

	for (unsigned i = 0; i < count - 1; i++)
		std::cout << "....";
	std::cout << "." << std::endl;
}

void table(unsigned startNumber, unsigned columns, const char* items) {
	__printTableColumnHeader(startNumber, columns);
}

void _printOrderedListBeginning() {
	std::cout << "[" << orderedListIndex++ << "] ";
}

void _printInputBoxLabel(const char* label) {
	std::cout << "    (+) " << label;
}

void _printAltInputBoxLabel(const char* label) {
	std::cout << "(+) " << label;
}

void inputLineBox(const char* label, char* output, unsigned maxWidth) {
	_printInputBoxLabel(label);
	std::cin.ignore();
	std::cin.getline(output, maxWidth);
}
