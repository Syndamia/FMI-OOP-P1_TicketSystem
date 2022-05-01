#include "Command.h"
#include <cstring>

Command::Command(const char* nameInMenu, void (*exec)()) {
	strcpy(this->nameInMenu, nameInMenu);
	this->exec = exec;
}

void Command::run() const {
	exec();
}

const char* Command::get_nameInMenu() const {
	return nameInMenu;
}
