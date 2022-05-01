#include "Toolbox.h"

int orderedListIndex = 1;

void printOrderedListElem(const char* message) {
	std::cout << orderedListIndex << ". ";
	printLine(message);
}

void resetOrderedList(int starter) {
	orderedListIndex = starter;
}
