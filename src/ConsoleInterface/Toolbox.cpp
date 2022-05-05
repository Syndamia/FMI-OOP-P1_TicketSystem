#include "Toolbox.hpp"

int orderedListIndex = 1;

void resetOrderedList(int starter) {
	orderedListIndex = starter;
}

void _printOrderedListBeginning() {
	std::cout << orderedListIndex << ". ";
}
