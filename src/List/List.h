#ifndef HEADER_LIST
#define HEADER_LIST

template <class T>
class List {
	T* elements;
	unsigned length;
	unsigned count;

	void resize();
	void free();
	void copyFrom(const List& other);

public:
	List(const T* elements, unsigned elementsCount);
	void add(const T& element);
	bool removeAt(unsigned index);
	T& operator[](unsigned index);
	const T& operator[](unsigned index) const;

	unsigned get_length() const;
	unsigned get_count() const;

	List();
	List& operator=(const List& other);
	List(const List& other);
	~List();

	List(List&& other);
	List& operator=(List&& other);
};

#endif
