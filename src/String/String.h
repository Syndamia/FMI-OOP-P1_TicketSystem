#ifndef HEADER_STRING
#define HEADER_STRING

class String {
	char* elems;
	unsigned count;
	unsigned length;

	void free();
	void copyFrom(const String& other);
	void moveFrom(String&& other);

public:
	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	String(String&& other);
	String& operator=(String&& other);

	int compare(const String& other);
	char operator[](unsigned index);
};

#endif
