#include "Menu.h"
#include "Toolbox.hpp"

Menu::Menu() : menuOptions() {}

Menu::Menu(const Command* commands, unsigned commandCount) {
	menuOptions = List<Command>(commands, commandCount);
}

void Menu::addCommand(const Command* command) {
	menuOptions.add(command);
}

void Menu::navigate() const {
	if (menuOptions.get_count() == 0) {
		printLine("Menu is empty!");
		return;
	}

	resetOrderedList();
	printOrderedListElem("Go Back");
	for (unsigned i = 0; i < menuOptions.get_count(); i++)
		printOrderedListElem(menuOptions[i].get_nameInMenu());

	int buffer = -1;
	while (buffer < 0 || buffer >= menuOptions.get_count()) {
		print("Execute No [0-");
		print(menuOptions.get_count());
		print("]: ");
		read(buffer);
	}

	if (buffer == 0) return;

	menuOptions[buffer - 1].run();
}
