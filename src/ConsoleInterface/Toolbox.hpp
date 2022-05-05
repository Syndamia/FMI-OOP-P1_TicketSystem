#ifndef HEADER_CONSOLEINTERFACE_TOOLBOX
#define HEADER_CONSOLEINTERFACE_TOOLBOX

#include "../String/String.h"
#include <iostream>

#define MAX_LINE_WIDTH 1024

void clear();

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

void _printOrderedListBeginning();

template <typename T>
void printOrderedListElem(const T& elem) {
	_printOrderedListBeginning();
	printLine(elem);
}

void resetOrderedList(int starter = 1);

void _printInputBoxLabel(const char* label);
void _printAltInputBoxLabel(const char* label);

template <typename T>
void inputBox(const char* label, T* output) {
	_printInputBoxLabel(label);
	std::cin >> *output;
}

void inputLineBox(const char* label, char* output, unsigned maxWidth);

void printTitle(const char* title);
void printSuccess(const char* message);
void printWarning(const char* message);
void printError(const char* message);

#endif
