#ifndef HEADER_CONSOLEINTERFACE_TOOLBOX
#define HEADER_CONSOLEINTERFACE_TOOLBOX

#include <iostream>

#define MAX_LINE_WIDTH 1024

void clear();
void titleBox(const char* title);
void subTitleBox(const char* title);

void successBox(const char* message);
void warningBox(const char* message);
void errorBox(const char* message);

void table(unsigned startNumber, unsigned columns, const char* items);

void inputLineBox(const char* label, char* output, unsigned maxWidth);
void inputLineSubBox(const char* label, char* output, unsigned maxWidth);
void resetOrderedList(int starter = 1);

void _printInputBoxLabel(const char* label);
void _printInputSubBoxLabel(const char* label);
void _printOrderedListBeginning();

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


template <typename T>
void printOrderedListElem(const T& elem) {
	_printOrderedListBeginning();
	printLine(elem);
}

template <typename T>
void inputBox(const char* label, T* output) {
	_printInputBoxLabel(label);
	std::cin >> *output;
}

template <typename T>
void inputSubBox(const char* label, T* output) {
	_printInputSubBoxLabel(label);
	std::cin >> *output;
}

#endif
