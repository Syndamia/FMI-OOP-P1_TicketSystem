#include "Menu.h"
#include "Toolbox.h"

Menu::Menu(const Command* commands, unsigned commandCount) {
	menuOptions = List<Command>(commands, commandCount);
}

void Menu::navigate() const {
	if (menuOptions.get_count() == 0) {
		std::cout << "Menu is empty!" << std::endl;
		return;
	}

	resetOrderedList();
	for (unsigned i = 0; i < menuOptions.get_count(); i++)
		printOrderedListElem(menuOptions[i].get_nameInMenu());

	unsigned buffer = 0;
	while (0 == buffer || buffer >= menuOptions.get_count()) {
		std::cout << "Execute No [1-" << menuOptions.get_count() << "]: ";
		std::cin >> buffer;
	}

	menuOptions[buffer - 1].run();
}
