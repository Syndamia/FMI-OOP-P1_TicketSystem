#include "Menu.h"
#include "Toolbox.hpp"

Menu::Menu(const Command* commands, unsigned commandCount) {
	menuOptions = List<Command>(commands, commandCount);
}

void Menu::navigate() const {
	if (menuOptions.get_count() == 0) {
		printLine("Menu is empty!");
		return;
	}

	resetOrderedList();
	for (unsigned i = 0; i < menuOptions.get_count(); i++)
		printOrderedListElem(menuOptions[i].get_nameInMenu());

	unsigned buffer = 0;
	while (0 == buffer || buffer >= menuOptions.get_count()) {
		print("Execute No [1-");
		print(menuOptions.get_count());
		print("]: ");
		read(buffer);
	}

	menuOptions[buffer - 1].run();
}
