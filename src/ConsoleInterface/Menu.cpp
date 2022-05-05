#include "Menu.h"
#include "Toolbox.hpp"
#include <cstring>

Menu::Menu() : Menu("Menu") {}

Menu::Menu(const char* title) : menuOptions() {
	strcpy(this->title, title);
}

Menu::Menu(const char* title, const Command* commands, unsigned commandCount) {
	menuOptions = List<Command>(commands, commandCount);
	strcpy(this->title, title);
}

void Menu::addCommand(const Command& command) {
	menuOptions.add(command);
}

bool error = false;
String errMessage;

void Menu::registerError(const char* message) {
	error = true;
	errMessage = message;
}

void Menu::navigate() const {
	if (menuOptions.get_count() == 0) {
		printLine("Menu is empty!");
		return;
	}

	unsigned buffer = 1; // We immedeately read the value of buffer, so this is fine

	while (buffer != 0) {
		printTitle(title);

		resetOrderedList(0);
		printOrderedListElem("Go Back");
		for (unsigned i = 0; i < menuOptions.get_count(); i++)
			printOrderedListElem(menuOptions[i].get_nameInMenu());

		if (error) {
			printError(errMessage.get_cstr());
			error = false;
		}

		_printInputBoxLabel("Execute No [0-");
		print(menuOptions.get_count());
		print("]: ");
		read(buffer);

		if (buffer > menuOptions.get_count())
			error = true;
		else if (buffer > 0)
			menuOptions[buffer - 1].run();
	}
}
