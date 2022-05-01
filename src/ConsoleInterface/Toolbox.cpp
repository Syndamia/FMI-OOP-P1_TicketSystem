#include "Toolbox.h"
#include <iostream>

void print(const char* message) {
	std::cout << message;
}

void printLine(const char* message) {
	std::cout << message << std::endl;
}

int orderedListIndex = 1;

void printOrderedListElem(const char* message) {
	std::cout << orderedListIndex << ". ";
	printLine(message);
}

void resetOrderedList(int starter) {
	orderedListIndex = starter;
}
