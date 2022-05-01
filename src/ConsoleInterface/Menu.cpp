#include "Menu.h"
#include "Toolbox.h"

void Menu::navigate() const {
	for (unsigned i = 0; i < menuOptions.get_count(); i++)
		printOrderedListElem(menuOptions[i].get_nameInMenu());
}
