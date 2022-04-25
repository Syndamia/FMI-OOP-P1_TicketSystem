#include "String.h"
#include <cstring>

/* Private */

void String::free() {
	delete[] str;
}

void String::copyFrom(const String& other) {
	str = new char[other.length];
	strcpy(str, other.str);
	length = other.length;
}

/* Public */

String::String(const char* str) {
	length = strlen(str) + 1; // capture terminating zero
	this->str = new char[length];
	strcpy(this->str, str);
}

String::String() : String("") {}

String::String(const String& other) {
	copyFrom(other);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

String::~String() {
	free();
}

String::String(String&& other) {
	str = other.str;
	other.str = nullptr;
	length = other.length;
}

String& String::operator=(String&& other) {
	if (this != &other) {
		delete[] str;
		str = other.str;
		other.str = nullptr;
		length = other.length;
	}
	return *this;
}

int String::compare(const String& other) {
	return strcmp(str, other.str);
}

char String::operator[](unsigned index) {
	return str[index];
}
