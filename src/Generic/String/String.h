#ifndef HEADER_STRING
#define HEADER_STRING

#include <istream>
#include <ostream>

class String {
	char* str;
	unsigned length;

	void free();
	void copyFrom(const String& other);

public:
	String(unsigned length);
	String(const char* str);
	const char* get_cstr() const;
	unsigned get_length() const;

	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	String(String&& other);
	String& operator=(String&& other);

	void read(std::istream& istr);
	void write(std::ostream& ostr);
	int compare(const String& other) const;
	char& operator[](unsigned index);

	friend std::istream& operator>>(std::istream& istr, String& event);
	friend std::ostream& operator<<(std::ostream& ostr, const String& event);
};

#endif
