#include "Toolbox.h"
#include <iostream>

void printLine(const char* message) {
	std::cout << message << std::endl;
}

int orderedListIndex = 1;

void printOrderedListElem(const char* message) {
	std::cout << orderedListIndex << ". ";
	printLine(message);
}

void resetOrderedList(int starter = 1) {
	orderedListIndex = starter;
}
