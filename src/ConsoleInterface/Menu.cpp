#include "Menu.h"
#include "Toolbox.h"

void Menu::navigate() const {
	resetOrderedList();
	for (unsigned i = 0; i < menuOptions.get_count(); i++)
		printOrderedListElem(menuOptions[i].get_nameInMenu());

	std::cout << "Execute No [0-" << menuOptions.get_count() << "]: ";
}
