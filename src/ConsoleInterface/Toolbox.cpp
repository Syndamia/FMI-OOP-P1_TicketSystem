#include "Toolbox.hpp"

void clear() {
	std::cout << u8"\033[2J\033[1;1H"; 
}

int orderedListIndex = 1;

void resetOrderedList(int starter) {
	orderedListIndex = starter;
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

void printTitle(const char* title) {
	std::cout << std::endl << "### " << title << " ###" << std::endl;
}

void printSuccess(const char* message) {
	std::cout << "<S> " << message << std::endl;
}

void printWarning(const char* message) {
	std::cout << "<W> " << message << std::endl;
}

void printError(const char* message) {
	std::cout << "<E> " << message << std::endl;
}

