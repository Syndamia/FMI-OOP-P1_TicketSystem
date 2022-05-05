#include "Menu.h"
#include "Toolbox.hpp"
#include <cstring>

Menu::Menu() : menuOptions() {
	strcpy(title, "Menu");
}

Menu::Menu(const Command* commands, unsigned commandCount, const char* title) {
	menuOptions = List<Command>(commands, commandCount);
	strcpy(this->title, title);
}

void Menu::addCommand(const Command& command) {
	menuOptions.add(command);
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

		_printInputBoxLabel("Execute No [0-");
		print(menuOptions.get_count());
		print("]: ");
		read(buffer);

		if (buffer > menuOptions.get_count())
			printError("Invalid menu option!");
		else if (buffer > 0)
			menuOptions[buffer - 1].run();
	}
}
