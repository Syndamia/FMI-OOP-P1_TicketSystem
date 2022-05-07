#include "String.h"
#include <cstring>

/* Private */

void String::free() {
	delete[] str;
}

void String::copyFrom(const String& other) {
	str = new char[other.length + 1];
	strncpy(str, other.str, other.length + 1);
	length = other.length;
}

/* Public */

String::String(unsigned length) {
	this->length = length;
	str = new char[length];
}

String::String(const char* str) {
	length = strlen(str);
	this->str = new char[length + 1]; // capture terminating zero
	strncpy(this->str, str, length + 1);
}

const char* String::get_cstr() const {
	return str;
}

unsigned String::get_length() const {
	return length;
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

char& String::operator[](unsigned index) {
	return str[index];
}
