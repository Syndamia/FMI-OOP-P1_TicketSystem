#ifndef HEADER_CONSOLEINTERFACE_MENU
#define HEADER_CONSOLEINTERFACE_MENU

/*! \file Menu.h
 *  \brief Stores the declaration of class Menu
 */

#include "Command.h"
#include "../List/List.hpp"

/*! \brief Handles navigation between multiple commands
 *
 * Shows the title, then below it an Error/Warning/Success message if set,
 * lists all command options as an enumerated list, takes command index
 * and calls the chosen command's run() function.
 */
class Menu {
	char title[256];
	List<Command> menuOptions;

	bool backExistsApp;
	bool isSubMenu;

public:
	//! Sets name as "Menu", leaves all flags to false and creates an empty Command list
	Menu();
	//! Copies title, saves flags and creates and empty Command list
	Menu(const char* title, bool backExistsApp, bool isSubMenu);
	//! Copies title, saves flags and copies commands
	Menu(const char* title, bool backExistsApp, bool isSubMenu, const Command* commands, unsigned commandCount);

	//! Adds a command to the internal Command list
	void addCommand(const Command& command);

	//! Tell Menu to show an error message next time it prints
	void registerError(const char* message) const;
	//! Tell Menu to show a warning message next time it prints
	void registerWarning(const char* message) const;
	//! Tell Menu to show a success message next time it prints
	void registerSuccess(const char* message) const;

	//! Lists commands and after user input executes an appropriate command run() function
	void navigate() const;
};

#endif
