#include "Menu.h"
#include "Toolbox.hpp"
#include <cstring>

Menu::Menu() : Menu("Menu", false, false) {}

Menu::Menu(const char* title, bool backExistsApp, bool isSubMenu) : menuOptions() {
	this->backExistsApp = backExistsApp;
	this->isSubMenu = isSubMenu;
	strcpy(this->title, title);
}

Menu::Menu(const char* title, bool backExistsApp, bool isSubMenu, const Command* commands, unsigned commandCount) {
	this->backExistsApp = backExistsApp;
	this->isSubMenu = isSubMenu;
	menuOptions = List<Command>(commands, commandCount);
	strcpy(this->title, title);
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
String msg;
MessageType msgType;

void Menu::registerError(const char* message) const {
	msg = message;
	msgType = Error;
}

void Menu::registerWarning(const char* message) const {
	msg = message;
	msgType = Warning;
}

void Menu::registerSuccess(const char* message) const {
	msg = message;
	msgType = Success;
}

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
			case Error: errorBox(msg.get_cstr()); msgType = NoPrint; break;
			case Warning: warningBox(msg.get_cstr()); msgType = NoPrint; break;
			case Success: successBox(msg.get_cstr()); msgType = NoPrint; break;
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

		_printAltInputBoxLabel("Execute No [0-");
		print(menuOptions.get_count());
		print("]: ");
		read(buffer);

		if (buffer > menuOptions.get_count())
			registerError("Invalid menu option!");
		else if (buffer > 0)
			menuOptions[buffer - 1].run();
	}
}
