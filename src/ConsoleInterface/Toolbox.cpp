#include "Toolbox.hpp"

int orderedListIndex = 1;

void resetOrderedList(int starter) {
	orderedListIndex = starter;
}

void _printOrderedListBeginning() {
	std::cout << orderedListIndex++ << ". ";
}

void _printInputBoxLabel(const char* label) {
	std::cout << "+ " << label;
}

void inputLineBox(const char* label, char* output, unsigned maxWidth) {
	_printInputBoxLabel(label);
	std::cin.getline(output, maxWidth);
}

void printTitle(const char* title) {
	std::cout << "## " << title << " ##" << std::endl;
}

void printSuccess(const char* message) {
	std::cout << ") " << message << std::endl;
}

void printError(const char* message) {
	std::cout << "! Err: " << message << std::endl;
}

