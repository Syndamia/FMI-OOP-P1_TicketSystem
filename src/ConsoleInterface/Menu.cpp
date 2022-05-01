#include "Menu.h"
#include "Toolbox.h"

Menu::Menu(const Command* commands, unsigned commandCount) {
	menuOptions = List<Command>();
	for (unsigned i = 0; i < commandCount; i++)
		menuOptions.add(commands[i]);
}

void Menu::navigate() const {
	resetOrderedList();
	for (unsigned i = 0; i < menuOptions.get_count(); i++)
		printOrderedListElem(menuOptions[i].get_nameInMenu());

	unsigned buffer = 0;
	while (0 == buffer || buffer >= menuOptions.get_count()) {
		std::cout << "Execute No [0-" << menuOptions.get_count() << "]: ";
		std::cin >> buffer;
	}

	menuOptions[buffer - 1].run();
}
