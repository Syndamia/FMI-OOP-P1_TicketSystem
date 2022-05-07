#include "Toolbox.hpp"

void clear() {
	// Clears console on Linux
	// Source: https://stackoverflow.com/a/52895729/12036073
	std::cout << u8"\033[2J\033[1;1H"; 
}

void _printSubBoxSpacing() {
	std::cout << "    ";
}

/* Title boxes */

void titleBox(const char* title) {
	std::cout << std::endl << "=== " << title << " ===" << std::endl;
}

void subTitleBox(const char* title) {
	std::cout << std::endl << "--- " << title << " ---" << std::endl;
}

/* Status boxes */

void successBox(const char* message) {
	std::cout << "<S> " << message << std::endl;
}

void successSubBox(const char* message) {
	_printSubBoxSpacing();
	successBox(message);
}

void warningBox(const char* message) {
	std::cout << "<W> " << message << std::endl;
}

void warningSubBox(const char* message) {
	_printSubBoxSpacing();
	warningBox(message);
}

void errorBox(const char* message) {
	std::cout << "<E> " << message << std::endl;
}

void errorSubBox(const char* message) {
	_printSubBoxSpacing();
	errorBox(message);
}

/* Input line boxes */

void _printInputBoxLabel(const char* label) {
	std::cout << "(+) " << label;
}

void __inputLineBoxGetInput(char* output, unsigned maxWidth, bool ignore) {
	if (ignore)
		std::cin.ignore();
	std::cin.getline(output, maxWidth);
}

void inputLineBox(const char* label, char* output, unsigned maxWidth, bool ignore) {
	_printInputBoxLabel(label);
	__inputLineBoxGetInput(output, maxWidth, ignore);
}

void inputLineSubBox(const char* label, char* output, unsigned maxWidth, bool ignore) {
	_printSubBoxSpacing();
	_printInputBoxLabel(label);
	__inputLineBoxGetInput(output, maxWidth, ignore);
}

void pressEnterToContinue(bool ignore) {
	char tmp;
	inputLineBox("[Press enter to continue]", &tmp, 1, ignore);
}

/* Ordered list */

int orderedListIndex = 1;

void _printOrderedListBeginning() {
	std::cout << "[" << orderedListIndex++ << "] ";
}

void resetOrderedList(int starter) {
	orderedListIndex = starter;
}

/* Table */

void __printTableHeaderNumber(unsigned number) {
	std::cout << ":" << ((number < 100) ? " " : "") << number << ((number < 10) ? " " : "");
}

void __printTableColumnHeader(unsigned start, unsigned count) {
	std::cout << ":   ";
	for (unsigned i = 0; i < count; i++)
		__printTableHeaderNumber(start++);
	std::cout << ":" << std::endl;

	for (unsigned i = 0; i <= count; i++)
		std::cout << "====";
	std::cout << "=" << std::endl;
}

void __printTableLine(unsigned columns) {
	std::cout << ":===";
	for (unsigned i = 0; i < columns; i++)
		std::cout << "+---";
	std::cout << ":" << std::endl;
}

void table(unsigned startNumber, unsigned columns, const char* items) {
	__printTableColumnHeader(startNumber, columns);

	__printTableHeaderNumber(startNumber);
	for (unsigned i = 0, colInd = 0, rowInd = 0; items[i] != '\0'; i++, (++colInd) %= columns) {
		if (colInd == 0 && i != 0) {
			std::cout << ":" << std::endl;
			__printTableLine(columns);
			__printTableHeaderNumber((++rowInd) + startNumber);
		}

		std::cout << ((colInd == 0) ? "║ " : "| ") << items[rowInd * columns + colInd] << " ";
	}
	std::cout << ":" << std::endl;
}

