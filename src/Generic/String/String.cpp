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
	str = new char[length + 1];
	str[length] = '\0';
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

String& String::operator+=(const char* str) {
	unsigned strLen = strlen(str);
	char* newStr = new char[length + strLen + 1];
	strncpy(newStr, this->str, length + 1);
	strncat(newStr, str, strLen + 1);

	delete[] this->str;
	this->str = newStr;
	length += strLen;

	return *this;
}

String& String::operator+=(unsigned number) {
	unsigned tempLen = number / 10 + 1;
	char* tmp = new char[tempLen + 1];
	tmp[tempLen] = '\0';
	for (unsigned i = tempLen - 1; i < tempLen; i--, number /= 10)
		tmp[i] = number % 10 + '0';

	*this += tmp;
	delete[] tmp;
	return *this;
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

void String::read(std::istream& istr) {
	istr.read((char*)&length, sizeof(length));
	istr.read(str, sizeof(char) * (length + 1));
}

void String::write(std::ostream& ostr) const {
	ostr.write((char*)&length, sizeof(length));
	ostr.write(str, sizeof(char) * (length + 1));
}

int String::compare(const String& other) const {
	return strcmp(str, other.str);
}

char& String::operator[](unsigned index) {
	return str[index];
}

std::istream& operator>>(std::istream& istr, String& event) {
	istr.getline(event.str, 1024);
	event.length = strlen(event.str);

	return istr;
}

std::ostream& operator<<(std::ostream& ostr, const String& event) {
	return ostr << event.str;
}
