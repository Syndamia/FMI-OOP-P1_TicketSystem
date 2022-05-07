#include "Toolbox.hpp"

void clear() {
	// Clears console on Linux
	// Source: https://stackoverflow.com/a/52895729/12036073
	std::cout << u8"\033[2J\033[1;1H"; 
}

void titleBox(const char* title) {
	std::cout << std::endl << "=== " << title << " ===" << std::endl;
}

void subTitleBox(const char* title) {
	std::cout << std::endl << "--- " << title << " ---" << std::endl;
}

/* Status boxes */

void __printSubBoxSpacing() {
	std::cout << "    ";
}

void successBox(const char* message) {
	std::cout << "<S> " << message << std::endl;
}

void successSubBox(const char* message) {
	__printSubBoxSpacing();
	successBox(message);
}

void warningBox(const char* message) {
	std::cout << "<W> " << message << std::endl;
}

void warningSubBox(const char* message) {
	__printSubBoxSpacing();
	warningBox(message);
}

void errorBox(const char* message) {
	std::cout << "<E> " << message << std::endl;
}

void errorSubBox(const char* message) {
	__printSubBoxSpacing();
	errorBox(message);
}


void _printOrderedListBeginning() {
	std::cout << "[" << orderedListIndex++ << "] ";
}

/* Input line boxes */

void _printInputBoxLabel(const char* label) {
	std::cout << "(+) " << label;
}

void _printInputSubBoxLabel(const char* label) {
	std::cout << "    ";
	_printInputBoxLabel(label);
}

void __inputLineBoxGetInput(char* output, unsigned maxWidth) {
	std::cin.ignore();
	std::cin.getline(output, maxWidth);
}

void inputLineBox(const char* label, char* output, unsigned maxWidth) {
	_printInputBoxLabel(label);
	__inputLineBoxGetInput(output, maxWidth);
}

void inputLineSubBox(const char* label, char* output, unsigned maxWidth) {
	_printInputSubBoxLabel(label);
	__inputLineBoxGetInput(output, maxWidth);
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

