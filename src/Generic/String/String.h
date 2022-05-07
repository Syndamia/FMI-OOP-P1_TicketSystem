#ifndef HEADER_STRING
#define HEADER_STRING

class String {
	char* str;
	unsigned count;
	unsigned length;

	void resize();
	void free();
	void copyFrom(const String& other);

public:
	String(const char* str);
	const char* get_cstr() const;
	unsigned get_count() const;
	unsigned get_length() const;

	String& operator+=(const String& other);
	String& operator+=(char character);

	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	String(String&& other);
	String& operator=(String&& other);

	int compare(const String& other) const;
	char operator[](unsigned index);
};

#endif
