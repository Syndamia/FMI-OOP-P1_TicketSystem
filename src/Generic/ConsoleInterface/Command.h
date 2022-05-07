#ifndef HEADER_CONSOLEINTERFACE_COMMAND
#define HEADER_CONSOLEINTERFACE_COMMAND

class Command {
	char nameInMenu[256];
	void (*exec)();

public:
	Command();
	Command(const char* nameInMenu, void (*exec)());
	void run() const;

	const char* get_nameInMenu() const;
};

#endif