#include "String.h"
#include <cstring>

/* Private */

void String::free() {
	delete[] str;
}

void String::copyFrom(const String& other) {
	this->str = new char[other.length];
	strcpy(this->str, other.str);
}
