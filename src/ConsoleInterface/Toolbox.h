#ifndef HEADER_CONSOLEINTERFACE_TOOLBOX
#define HEADER_CONSOLEINTERFACE_TOOLBOX


template <class T>
void print(const T* item);
template <class T>
void printLine(const T* item);
template <class T>
void print(const T& item);
template <class T>
void printLine(const T& item);

void printOrderedListElem(const char* message);
void resetOrderedList(int starter = 1);

#endif
