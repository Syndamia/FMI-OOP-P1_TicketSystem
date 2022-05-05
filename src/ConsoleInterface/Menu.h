#ifndef HEADER_CONSOLEINTERFACE_MENU
#define HEADER_CONSOLEINTERFACE_MENU

#include "Command.h"
#include "../List/List.hpp"

class Menu {
	char title[256];
	List<Command> menuOptions;

public:
	Menu();
	Menu(const char* title);
	Menu(const char* title, const Command* commands, unsigned commandCount);

	void addCommand(const Command& command);
	void navigate() const;
};

#endif
