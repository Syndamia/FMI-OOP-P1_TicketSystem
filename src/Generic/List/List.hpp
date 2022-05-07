#ifndef HEADER_LIST
#define HEADER_LIST

#include <istream>
#include <ostream>

template <class T>
class List {
protected:
	T* elements;
	unsigned length;
	unsigned count;

	void resize();
	void free();
	void copyFrom(const List& other);

public:
	List(const T* elements, unsigned elementsCount);
	void add(T element);
	void insertAt(T element, unsigned index);
	bool removeAt(unsigned index);
	unsigned findIndex(const T& element) const;
	bool contain(const T& element) const;
	T& operator[](unsigned index);
	const T& operator[](unsigned index) const;

	std::istream& read(std::istream& istr);
	std::ostream& write(std::ostream& ostr) const;

	unsigned get_length() const;
	unsigned get_count() const;

	List();
	List& operator=(const List& other);
	List(const List& other);
	~List();

	List(List&& other);
	List& operator=(List&& other);
};

/* Private */

template <class T>
void List<T>::resize() {
	length = (length == 0) ? 8 : length << 1;
	T* temp = new T[length];
	for (int i = 0; i < count; i++)
		temp[i] = elements[i];
	delete[] elements;
	elements = temp;
}

template <class T>
void List<T>::free() {
	delete[] elements;
}

template <class T>
void List<T>::copyFrom(const List& other) {
	elements = new T[other.length];
	for (int i = 0; i < other.count; i++)
		elements[i] = other.elements[i];
	length = other.length;
	count = other.count;
}

/* Public */

template <class T>
List<T>::List(const T* elements, unsigned elementsCount) {
	length = 8;
	count = elementsCount;
	this->elements = new T[length];
	for (unsigned i = 0; i < count; i++)
		this->elements[i] = elements[i];
}

template <class T>
void List<T>::add(T element) {
	if (length == count) resize();

	elements[count++] = element;
}

template <class T>
void List<T>::insertAt(T element, unsigned index) {
	if (index >= count) {
		add(element);
		return;
	}
	if (length == count) resize();

	for (unsigned i = count; i > index; i--)
		elements[i] = elements[i - 1];

	elements[index] = element;
	count++;
}

template <class T>
bool List<T>::removeAt(unsigned index) {
	if (index >= count) return false;

	for (int i = index; i < count; i++)
		elements[i] = elements[i + 1];
	count--;
	return true;
}

template <class T>
unsigned List<T>::findIndex(const T& element) const {
	unsigned ind = 0;
	while (ind < count && elements[ind].compare(element) != 0)
		ind++;
	return ind;
}

template <class T>
bool List<T>::contain(const T& element) const {
	return findIndex(element) < count;
}

template <class T>
T& List<T>::operator[](unsigned index) {
	return elements[index];
}

template <class T>
const T& List<T>::operator[](unsigned index) const {
	return elements[index];
}

template <class T>
std::istream& List<T>::read(std::istream& istr) {
	istr.read((char*)&length, sizeof(length));
	istr.read((char*)&count, sizeof(count));

	delete[] elements;
	elements = new T[length];

	for (int i = 0; i < count; i++)
		elements[i].read(istr); // disgusting

	return istr;
}

template <class T>
std::ostream& List<T>::write(std::ostream& ostr) const {
	ostr.write((const char*)&length, sizeof(length));
	ostr.write((const char*)&count, sizeof(count));

	for (int i = 0; i < count; i++)
		elements[i].write(ostr); // disgusting

	return ostr;
}

template <class T>
unsigned List<T>::get_length() const {
	return length;
}

template <class T>
unsigned List<T>::get_count() const {
	return count;
}

// Rule of 4

template <class T>
List<T>::List() : List(nullptr, 0) {}

template <class T>
List<T>& List<T>::operator=(const List& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T>
List<T>::List(const List& other) {
	copyFrom(other);
}

template <class T>
List<T>::~List() {
	free();
}

// Move semantics

template <class T>
List<T>::List(List&& other) {
	length = other.length;
	count = other.count;
	elements = other.elements;
	other.elements = nullptr;
}

template <class T>
List<T>& List<T>::operator=(List&& other) {
	if (this != &other) {
		free();
		length = other.length;
		count = other.count;
		elements = other.elements;
		other.elements = nullptr;
	}
	return *this;
}

#endif
