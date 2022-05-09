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

/*!
 * Allocated with length + 1 size, so there is a terminating zero at the end.
 */
String::String(unsigned length) {
	this->length = length;
	str = new char[length + 1];
	str[length] = '\0';
}

/*! \params str C-style string
 */
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

char& String::operator[](unsigned index) {
	return str[index];
}

/*! \params str C-style string
 */
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

/*!
 * Converts the number to a C-style string and then uses += to append it.
 */
String& String::operator+=(unsigned number) {
	unsigned tempLen = 0;
	for (unsigned tmp = number; tmp > 0 || tempLen == 0; tmp /= 10)
		tempLen++;

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

/*! \param istr An input stream
 *
 * Directly reads bytes from stream (calls read() function).
 * First reads the string length, then the underlying C-style string (including terminating zero).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ifstream
 */
void String::read(std::istream& istr) {
	istr.read((char*)&length, sizeof(length));
	istr.read(str, sizeof(char) * (length + 1));
}

/*! \param ostr An output stream
 *
 * Directly writes bytes to stream (calls write() function).
 * First writes the string length, then the underlying C-style string (including terminating zero).
 * 
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ofstream
 */
void String::write(std::ostream& ostr) const {
	ostr.write((char*)&length, sizeof(length));
	ostr.write(str, sizeof(char) * (length + 1));
}

/*! \params other C-style string
 *  \returns strcmp between underlying C-style string and "other"
 */
int String::compare(const String& other) const {
	return strcmp(str, other.str);
}

/*!
 * Uses the stream's getline function to read the data.
 *
 * \warning It takes at most 1024 characters from the stream!
 * \note Best used with std::cin or text std::ifstream
 */
std::istream& operator>>(std::istream& istr, String& event) {
	istr.getline(event.str, 1024);
	event.length = strlen(event.str);

	return istr;
}

/*!
 * Uses the stream's << operator to write the underlying C-style string
 *
 * \note Best used with std::cout or text std::ofstream
 */
std::ostream& operator<<(std::ostream& ostr, const String& event) {
	return ostr << event.str;
}
