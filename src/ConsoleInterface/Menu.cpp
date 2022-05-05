#include "Menu.h"
#include "Toolbox.hpp"

Menu::Menu() : menuOptions() {}

Menu::Menu(const Command* commands, unsigned commandCount) {
	menuOptions = List<Command>(commands, commandCount);
}

void Menu::addCommand(const Command& command) {
	menuOptions.add(command);
}

void Menu::navigate() const {
	if (menuOptions.get_count() == 0) {
		printLine("Menu is empty!");
		return;
	}

	resetOrderedList(0);
	printOrderedListElem("Go Back");
	for (unsigned i = 0; i < menuOptions.get_count(); i++)
		printOrderedListElem(menuOptions[i].get_nameInMenu());

	unsigned buffer = 0; // 0 is optionless continue, 1 is exit, others are options

	while (buffer != 1) {
		print("Execute No [0-");
		print(menuOptions.get_count());
		print("]: ");
		read(buffer);

		if (++buffer > 0)
			menuOptions[buffer - 1].run();
	}
}
