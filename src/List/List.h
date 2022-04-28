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
	void add(const T& element);
	bool removeAt(unsigned index);
	T& operator[](unsigned index);

	List();
	List& operator=(const List& other);
	List(const List& other);
	~List();

	List(List&& other);
	List& operator=(List&& other);
};

#endif
