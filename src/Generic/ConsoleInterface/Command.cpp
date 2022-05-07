#include "Command.h"
#include <cstring>

Command::Command() : Command("", nullptr) {}

Command::Command(const char* nameInMenu, void (*exec)()) {
	strcpy(this->nameInMenu, nameInMenu);
	this->exec = exec;
}

void Command::run() const {
	if (exec != nullptr)
		exec();
}

const char* Command::get_nameInMenu() const {
	return nameInMenu;
}
