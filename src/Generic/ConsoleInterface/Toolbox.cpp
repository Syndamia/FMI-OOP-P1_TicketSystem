#include "Toolbox.hpp"

/*!
 * Erases display and moves cursor to top left corner via ANSI escape sequences: \c ESC[2J \c ESC[1;1H
 *
 * \warning Not all terminals support any or all ANSI escape sequences
 *
 * \note Source: https://stackoverflow.com/a/52895729/12036073
 */
void clear() {
	std::cout << u8"\033[2J\033[1;1H"; 
}

/*!
 * Sub boxes are like normal boxes, but indented with 4 spaces.
 */
void _printSubBoxSpacing() {
	std::cout << "    ";
}

/* Title boxes */

/*! \param title C-style string, there are no size checks so it could wrap
 *
 * Prints the title, surrounded by "===".
 */
void titleBox(const char* title) {
	std::cout << std::endl << "=== " << title << " ===" << std::endl;
}

/*! \param title C-style string, there are no size checks so it could wrap
 *
 * Prints the title, surrounded by "---".
 */
void subTitleBox(const char* title) {
	std::cout << std::endl << "--- " << title << " ---" << std::endl;
}

/* Status boxes */

/*! \param message C-style string, there are no size checks so it could wrap
 *
 * Success boxes start with "<S>" and print the message.
 *
 * \remark Success/Warning/Error boxes start with "<C>" where C is an appropriate character.
 */
void successBox(const char* message) {
	std::cout << "<S> " << message << std::endl;
}

/*!
 * \copydetails successBox()
 * \sa _printSubBoxSpacing()
 */
void successSubBox(const char* message) {
	_printSubBoxSpacing();
	successBox(message);
}

/*! \param message C-style string, there are no size checks so it could wrap
 *
 * Warning boxes start with "<W>" and print the message.
 *
 * \remark Success/Warning/Error boxes start with "<C>" where C is an appropriate character.
 */
void warningBox(const char* message) {
	std::cout << "<W> " << message << std::endl;
}

/*!
 * \copydetails warningBox()
 * \sa _printSubBoxSpacing()
 */
void warningSubBox(const char* message) {
	_printSubBoxSpacing();
	warningBox(message);
}

/*! \param message C-style string, there are no size checks so it could wrap
 *
 * Error boxes start with "<E>" and print the message.
 *
 * \remark Success/Warning/Error boxes start with "<C>" where C is an appropriate character.
 */
void errorBox(const char* message) {
	std::cout << "<E> " << message << std::endl;
}

/*!
 * \copydetails errorBox()
 * \sa _printSubBoxSpacing()
 */
void errorSubBox(const char* message) {
	_printSubBoxSpacing();
	errorBox(message);
}

/* Input line boxes */

/*! \param label C-style string, there are no size checks so it could wrap
 *
 * Prints "(+)" and then the given label.
 * It doesn't create spacing after label, so it should exist in the label itself.
 *
 * \remark Semi-internal means the function is defined in the header out of necessity (for templated functions)
 */
void _printInputBoxLabel(const char* label) {
	std::cout << "(+) " << label;
}

void __inputLineBoxGetInput(char* output, unsigned maxWidth, bool ignore) {
	if (ignore)
		std::cin.ignore();
	std::cin.getline(output, maxWidth);
}

/*! \param label C-style string, there are no size check so it could wrap
 *  \param output Pointer to a char array
 *  \param maxWidth Maximum count of characters to read from user input. output MUST be able to hold that many characters!
 *  \param ignore Whether or not to ignore the first new-line delimiter.
 *         true by default, should be set to false only when an inputLineBox/SubBox has been issued directly prior or when it's the very first issued box command.
 *
 *  Prints "(+)" before the label.
 */
void inputLineBox(const char* label, char* output, unsigned maxWidth, bool ignore) {
	_printInputBoxLabel(label);
	__inputLineBoxGetInput(output, maxWidth, ignore);
}

/*!
 * \copydetails inputLineBox()
 * \sa _printSubBoxSpacing()
 */
void inputLineSubBox(const char* label, char* output, unsigned maxWidth, bool ignore) {
	_printSubBoxSpacing();
	_printInputBoxLabel(label);
	__inputLineBoxGetInput(output, maxWidth, ignore);
}

/*! \param ignore Whether or not to ignore the first new-line delimiter.
 *         true by default, should be set to false only when an inputLineBox/SubBox has been issued directly prior or when it's the very first issued box command.
 *
 * Prints a "Press enter to continue" message and waits for the user
 */
void pressEnterToContinue(bool ignore) {
	char tmp;
	inputLineBox("[Press enter to continue]", &tmp, 1, ignore);
}

/* Ordered list */

int orderedListIndex = 1;

/*!
 * Prints the latests ordered list index, surrounded by square brackets, and increments the ordered list index.
 *
 * \remark There are no size checks, so list index could overflow.
 *
 * \remark Semi-internal means the function is defined in the header out of necessity (for templated functions)
 */

void _printOrderedListBeginning() {
	std::cout << "[" << orderedListIndex++ << "] ";
}

/*! \param starter Sets the starting number by which ordered list will enumerate
 *
 * \remark Although starter can be a negative number, ordered list will always increment up the number.
 */
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

/*! \param startNumber The number by which column and row enumeration begins
 *  \param columns How many columns the table should have
 *  \param items C-style string, each cell is a single character from the string
 *
 * Prints a string as a grid/table of characters from top to bottom, left to right.
 * The first character is on the top left, the last one is on the bottom right.
 *
 * Table is printed until a terminating zero is encountered.
 * The rows are "calculated" from the columns count and the items length.
 */
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

