#include "String.h"
#include <cstring>

/* Private */

void String::free() {
	delete[] str;
}

void String::copyFrom(const String& other) {
	str = new char[other.length];
	strncpy(str, other.str, other.count);
	length = other.length;
	count = other.count;
}

/* Public */

String::String(const char* str) {
	count = length = strlen(str) + 1; // capture terminating zero
	this->str = new char[length];
	strncpy(this->str, str, count);
}

const char* String::get_cstr() const {
	return str;
}

String& String::operator+=(const String& other) {
	char* newStr = new char[length + other.length + 1];
	strncpy(newStr, str, length);
	strncat(newStr, other.str, other.length + 1);

	delete[] str;
	str = newStr;
	length += other.length;

	return *this;
}

String& String::operator+=(char other) {
	if ()
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

int String::compare(const String& other) const {
	return strcmp(str, other.str);
}

char String::operator[](unsigned index) {
	return str[index];
}
