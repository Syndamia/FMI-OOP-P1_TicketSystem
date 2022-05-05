#ifndef HEADER_CONSOLEINTERFACE_TOOLBOX
#define HEADER_CONSOLEINTERFACE_TOOLBOX

#include <iostream>

template <class T>
void read(T* storage) {
	std::cin >> storage;
}

template <class T>
void read(T& storage) {
	std::cin >> storage;
}

template <class T>
void print(const T* item) {
	std::cout << item;
}

template <class T>
void printLine(const T* item) {
	std::cout << item << std::endl;
}

template <class T>
void print(const T& item) {
	std::cout << item;
}

template <class T>
void printLine(const T& item) {
	std::cout << item << std::endl;
}

int orderedListIndex = 1;

void printOrderedListElem(const char* message) {
	std::cout << orderedListIndex << ". ";
	printLine(message);
}

void resetOrderedList(int starter = 1) {
	orderedListIndex = starter;
}

template <typename T>
T inputBox(const char* label) {
	print(label);
	T temp;
	std::cin >> temp;
	return temp;
}

#endif
