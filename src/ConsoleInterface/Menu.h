#ifndef HEADER_CONSOLEINTERFACE_MENU
#define HEADER_CONSOLEINTERFACE_MENU

#include "Command.h"
#include "../List/List.h"

class Menu {
	List<Command> menuOptions;

public:
	Menu(const Command* commands, unsigned commandCount);
	void navigate() const;
};

#endif
