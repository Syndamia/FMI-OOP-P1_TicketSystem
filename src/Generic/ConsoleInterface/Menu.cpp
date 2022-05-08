#include "Menu.h"
#include "Toolbox.hpp"
#include <cstring>

Menu::Menu() : Menu("Menu", false, false) {}

/*! \param title C-style string, class stores at most 255 characters (last character is always terminating zero)
 *  \param backExistsApp Flag whether or not to list the 0-th option as "Exit", rather than "Go Back"
 *  \param isSubMenu Flag whether or not to show the title as a subTitle or not
 */
Menu::Menu(const char* title, bool backExistsApp, bool isSubMenu) : menuOptions() {
	this->backExistsApp = backExistsApp;
	this->isSubMenu = isSubMenu;
	strncpy(this->title, title, 255);
	this->title[255] = '\0';
}

/*! \param title C-style string, class stores at most 255 characters (last character is always terminating zero)
 *  \param backExistsApp Flag whether or not to list the 0-th option as "Exit", rather than "Go Back"
 *  \param isSubMenu Flag whether or not to show the title as a subTitle or not
 *  \param commands Pointer to an array of Command instances
 *  \param commandCount Number of elements that "commands" points to
 */
Menu::Menu(const char* title, bool backExistsApp, bool isSubMenu, const Command* commands, unsigned commandCount) {
	this->backExistsApp = backExistsApp;
	this->isSubMenu = isSubMenu;
	menuOptions = List<Command>(commands, commandCount);
	strncpy(this->title, title, 255);
	this->title[255] = '\0';
}

void Menu::addCommand(const Command& command) {
	menuOptions.add(command);
}

enum MessageType {
	NoPrint,
	Success,
	Warning,
	Error,
};
const char* msg;
MessageType msgType;

/*! \param message C-style string, saves to pointer for later reuse when showing the message.
 *
 * Stores the message pointer in a global variable (in the cpp file) and
 * sets it's type as an Error in another global variable (in the cpp file).
 *
 * The next time the whole Menu is shown, the message will appear below the title.
 */
void Menu::registerError(const char* message) const {
	msg = message;
	msgType = Error;
}

/*! \param message C-style string, saves to pointer for later reuse when showing the message.
 *
 * Stores the message pointer in a global variable (in the cpp file) and
 * sets it's type as a Warning in another global variable (in the cpp file).
 *
 * The next time the whole Menu is shown, the message will appear below the title.
 */
void Menu::registerWarning(const char* message) const {
	msg = message;
	msgType = Warning;
}

/*! \param message C-style string, saves to pointer for later reuse when showing the message.
 *
 * Stores the message pointer in a global variable (in the cpp file) and
 * sets it's type as Success in another global variable (in the cpp file).
 *
 * The next time the whole Menu is shown, the message will appear below the title.
 */
void Menu::registerSuccess(const char* message) const {
	msg = message;
	msgType = Success;
}

/*!
 * Prints the title, then an Error/Warning/Sucess message (if set),
 * prints all command names as an ordered list (starting from 1),
 * waits for user input to select one of those commands (by list number)
 * and finally executes the appropriate command's run() function.
 *
 * After the run() function exists, everything is reprinted.
 * The 0 list index is always "Go Back"/"Exit" and it always stops the reprinting loop.
 *
 * If there are no commands, prints "Menu is empty!".
 * If user input doesn't correspond to any command, registers an error message and reprints.
 */
void Menu::navigate() const {
	if (menuOptions.get_count() == 0) {
		printLine("Menu is empty!");
		return;
	}

	unsigned buffer = 1; // We immedeately read the value of buffer, so this is fine

	while (buffer != 0) {
		clear();
		if (isSubMenu)
			subTitleBox(title);
		else
			titleBox(title);

		switch(msgType) {
			case Error: errorBox(msg); msgType = NoPrint; break;
			case Warning: warningBox(msg); msgType = NoPrint; break;
			case Success: successBox(msg); msgType = NoPrint; break;
			case NoPrint: printLine(""); break;
		}
		printLine("");

		resetOrderedList(0);
		if (backExistsApp)
			printOrderedListElem("Exit");
		else
			printOrderedListElem("Go Back");

		for (unsigned i = 0; i < menuOptions.get_count(); i++)
			printOrderedListElem(menuOptions[i].get_nameInMenu());

		_printInputBoxLabel("Execute No [0-");
		print(menuOptions.get_count());
		print("]: ");
		read(buffer);

		if (buffer > menuOptions.get_count())
			registerError("Invalid menu option!");
		else if (buffer > 0)
			menuOptions[buffer - 1].run();
	}
}
