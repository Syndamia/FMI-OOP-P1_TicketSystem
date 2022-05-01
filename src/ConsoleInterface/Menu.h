#ifndef HEADER_CONSOLEINTERFACE_COMMAND
#define HEADER_CONSOLEINTERFACE_COMMAND

class Command {
	char message[256];
	void (*exec)(char input);
};

#endif
