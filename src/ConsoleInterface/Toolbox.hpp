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

void _printOrderedListBeginning();

template <typename T>
void printOrderedListElem(const T& elem) {
	_printOrderedListBeginning();
	printLine(elem);
}

void resetOrderedList(int starter);

void inputBoxLabel(const char* label) {
	std::cout << "+ " << label;
}

template <typename T>
void inputBox(const char* label, T* output) {
	inputBoxLabel(label);
	std::cin >> *output;
}

void inputLineBox(const char* label, char* output, unsigned maxWidth) {
	inputBoxLabel(label);
	std::cin.getline(output, maxWidth);
}

void printTitle(const char* title) {
	std::cout << "## " << title << " ##" << std::endl;
}

void printSuccess(const char* message) {
	std::cout << ") " << message << std::endl;
}

void printError(const char* message) {
	std::cout << "! Err: " << message << std::endl;
}

#endif
