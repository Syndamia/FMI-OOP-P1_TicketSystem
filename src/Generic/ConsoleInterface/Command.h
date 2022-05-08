#ifndef HEADER_CONSOLEINTERFACE_COMMAND
#define HEADER_CONSOLEINTERFACE_COMMAND

/*! \file Command.h
 *  \brief Stores the declaration of class Command
 */

/*! \brief Stores a 256 character name and a function pointer to be executed when calling run()
 *
 * Menu uses this class for a more generic implementation of it's navigate function.
 */
class Command {
	char nameInMenu[256];
	void (*exec)();

public:
	//! Leaves name empty and exec function pointer to nullptr
	Command();
	//! Copies contents of nameInMenu and stores exec
	Command(const char* nameInMenu, void (*exec)());
	//! Executes the stored function pointer
	void run() const;

	const char* get_nameInMenu() const;
};

#endif
