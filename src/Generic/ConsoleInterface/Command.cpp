#include "Command.h"
#include <cstring>

Command::Command() : Command("", nullptr) {}

/*! \param nameInMenu C-style string, class stores at most 255 characters (last character is always terminating zero)
 *  \param exec Function pointer that will be executed when run() is called. Can be nullptr.
 */
Command::Command(const char* nameInMenu, void (*exec)()) {
	strncpy(this->nameInMenu, nameInMenu, 255);
	this->nameInMenu[255] = '\0';
	this->exec = exec;
}

/*! Executes the stored function pointer, when it's not nullptr. Otherwise does nothing.
 */
void Command::run() const {
	if (exec != nullptr)
		exec();
}

const char* Command::get_nameInMenu() const {
	return nameInMenu;
}
