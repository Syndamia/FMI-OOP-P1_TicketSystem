#ifndef HEADER_CONSOLEINTERFACE_MENU
#define HEADER_CONSOLEINTERFACE_MENU

#include "Command.h"
#include "../List/List.hpp"

class Menu {
	char title[256];
	List<Command> menuOptions;

	bool backExistsApp;
	bool isSubMenu;

public:
	Menu();
	Menu(const char* title, bool backExistsApp, bool isSubMenu);
	Menu(const char* title, bool backExistsApp, bool isSubMenu, const Command* commands, unsigned commandCount);

	void addCommand(const Command& command);

	void registerError(const char* message) const;
	void registerWarning(const char* message) const;
	void registerSuccess(const char* message) const;
	void navigate() const;
};

#endif
