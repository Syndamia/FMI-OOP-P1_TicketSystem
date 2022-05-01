#ifndef HEADER_CONSOLEINTERFACE_TOOLBOX
#define HEADER_CONSOLEINTERFACE_TOOLBOX

#include <iostream>

void print(const char* message);
void printLine(const char* message);

void printOrderedListElem(const char* message);
void resetOrderedList(int starter = 1);

#endif
