#ifndef HEADER_CONSOLEINTERFACE_TOOLBOX
#define HEADER_CONSOLEINTERFACE_TOOLBOX

#include "../String/String.h"
#include <iostream>

#define MAX_LINE_WIDTH 1024

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

template <typename T>
void printOrderedListElem(const T& elem) {
	std::cout << orderedListIndex << ". ";
	printLine(elem);
}

void resetOrderedList(int starter = 1) {
	orderedListIndex = starter;
}

void inputBoxLabel(const char* label) {
	std::cout << "+ " << label;
}

template <typename T>
void inputBox(const char* label, T* output) {
	inputBoxLabel(label);
	std::cin >> output;
}

void inputLineBox(const char* label, char* output, unsigned maxWidth) {
	inputBoxLabel(label);
	std::cin.getline(output, maxWidth);
}

#endif
