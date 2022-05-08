#ifndef HEADER_LIST
#define HEADER_LIST

/*! \file List.hpp
 *  \brief Stores declaration and definition of templated class List
 */

#include <istream>
#include <ostream>

/*! \brief Templated class that stores an array of elements in dynamic memory
 *
 * \warning findIndex(), contain(), read(), write(), operator<<() and operator>>() require the type to have defined a couple of functions.
 * \sa findIndex()
 * \sa contain()
 * \sa read()
 * \sa write()
 * \sa operator<<()
 * \sa operator>>()
 */
template <typename T>
class List {
protected:
	T* elements;
	unsigned length;
	unsigned count;

	void resize();
	void free();
	void copyFrom(const List& other);

public:
	//! Copies all elements in given array
	List(const T* elements, unsigned elementsCount);
	//! Adds an element
	void add(const T& element);
	//! Inserts element at given index
	void insertAt(const T& element, unsigned index);
	//! Removes element at index
	bool removeAt(unsigned index);
	//! Finds the index of element
	unsigned findIndex(const T& element) const;
	bool contain(const T& element) const;
	//! Returns reference to element at index
	T& operator[](unsigned index);
	//! Returns constant reference to element at index
	const T& operator[](unsigned index) const;

	//! Appends elements from other list
	List<T>& operator+=(const List<T> other);

	//! Reads from stream
	std::istream& read(std::istream& istr);
	//! Writes to stream
	std::ostream& write(std::ostream& ostr) const;

	//! Returns the length
	unsigned get_length() const;
	//! Returns the count
	unsigned get_count() const;

	List();
	List& operator=(const List& other);
	List(const List& other);
	~List();

	List(List&& other);
	List& operator=(List&& other);
};

//! Reads List from stream with >> operator
template <typename T>
std::istream& operator>>(std::istream& istr, List<T>& obj);
//! Writes List to stream with << operator
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const List<T>& obj);

/* Private */

template <typename T>
void List<T>::resize() {
	length = (length == 0) ? 8 : length << 1;
	T* temp = new T[length];
	for (int i = 0; i < count; i++)
		temp[i] = elements[i];
	delete[] elements;
	elements = temp;
}

template <typename T>
void List<T>::free() {
	delete[] elements;
}

template <typename T>
void List<T>::copyFrom(const List& other) {
	elements = new T[other.length];
	for (int i = 0; i < other.count; i++)
		elements[i] = other.elements[i];
	length = other.length;
	count = other.count;
}

/* Public */

template <typename T>
List<T>::List(const T* elements, unsigned elementsCount) {
	length = 8;
	count = elementsCount;
	this->elements = new T[length];
	for (unsigned i = 0; i < count; i++)
		this->elements[i] = elements[i];
}

/*!
 * Resizes internal array if there is no space for additional elements.
 */
template <typename T>
void List<T>::add(const T& element) {
	if (length == count) resize();

	elements[count++] = element;
}

/*!
 * If index is after the last element, the element is just added.
 * Otherwise all elements after the index are shifted right and element is put in place.
 *
 * Resizes internal array if there is no space for additional elements.
 */
template <typename T>
void List<T>::insertAt(const T& element, unsigned index) {
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

/*! \returns Wether element could be removed
 *
 * If index is after that of the last element, nothing is done and false is returned.
 * Otherwise elements after index are shifted right and count is reduced.
 */
template <typename T>
bool List<T>::removeAt(unsigned index) {
	if (index >= count) return false;

	for (int i = index; i < count; i++)
		elements[i] = elements[i + 1];
	count--;
	return true;
}

/*! \returns Index of element. If element isn't found, returns the count of element.
 *
 * \warning The function depends on the type having a function "compare" defined, which takes two elements and returns a number <0 if elem1 < elem2, >0 if elem1 > elem2, 0 if elem1 == elem2
 * \note Searching is done linearly
 */
template <typename T>
unsigned List<T>::findIndex(const T& element) const {
	unsigned ind = 0;
	while (ind < count && elements[ind].compare(element) != 0)
		ind++;
	return ind;
}

/*! \returns Whether the element is contained in the current List
 *
 * \warning Function depends on findIndex(), which means the same "compare" function must be defined in the type
 * \sa findIndex()
 */
template <typename T>
bool List<T>::contain(const T& element) const {
	return findIndex(element) < count;
}

template <typename T>
T& List<T>::operator[](unsigned index) {
	return elements[index];
}

template <typename T>
const T& List<T>::operator[](unsigned index) const {
	return elements[index];
}

template <typename T>
List<T>& List<T>::operator+=(const List<T> other) {
	for (unsigned i = 0; i < other.length; i++)
		add(other[i]);
	return *this;
}

/*! \param istr An input stream
 *
 * Directly reads bytes from stream (calls read() function).
 * Any stored values are deleted and replaced with those from the stream.
 * 
 * \warning The function depends on the type having a function "read" defined, which takes an std::istream& and writes it's data to it. Return type doesn't matter.
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ifstream
 */
template <typename T>
std::istream& List<T>::read(std::istream& istr) {
	istr.read((char*)&length, sizeof(length));
	istr.read((char*)&count, sizeof(count));

	delete[] elements;
	elements = new T[length];

	for (int i = 0; i < count; i++)
		elements[i].read(istr);

	return istr;
}

/*! \param ostr An output stream
 *
 * Directly writes bytes to stream (calls write() function).
 * 
 * \warning The function depends on the type having a function "write" defined, which takes an std::ostream& and writes it's data to it. Return type doesn't matter.
 * \remark Doesn't alter the stream in any other way.
 * \note Best used with binary ofstream
 */
template <typename T>
std::ostream& List<T>::write(std::ostream& ostr) const {
	ostr.write((const char*)&length, sizeof(length));
	ostr.write((const char*)&count, sizeof(count));

	for (int i = 0; i < count; i++)
		elements[i].write(ostr);

	return ostr;
}

/*!
 * Length is the size of the underlying array (allocated memory).
 */
template <typename T>
unsigned List<T>::get_length() const {
	return length;
}

/*!
 * Count is the amount of elements that are stored.
 */
template <typename T>
unsigned List<T>::get_count() const {
	return count;
}

// Rule of 4

template <typename T>
List<T>::List() : List(nullptr, 0) {}

template <typename T>
List<T>& List<T>::operator=(const List& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
List<T>::List(const List& other) {
	copyFrom(other);
}

template <typename T>
List<T>::~List() {
	free();
}

// Move semantics

template <typename T>
List<T>::List(List&& other) {
	length = other.length;
	count = other.count;
	elements = other.elements;
	other.elements = nullptr;
}

template <typename T>
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

/* Outside of class */

/*!
 * Uses the stream's >> operator to read and parse the elements.
 * The first item in the stream should be the count.
 *
 * \warning The function depends on the type having the operator >> defined, which takes an std::istream& and writes it's data to it. Return type doesn't matter.
 * \note Best used with std::cin or text std::ifstream
 */
template <typename T>
std::istream& operator>>(std::istream& istr, List<T>& obj) {
	List<T> newObj;
	unsigned count;
	istr >> count;

	T temp;
	for (int i = 0; i < count; i++) {
		istr >> temp;
		obj.add(temp);
	}

	return istr;
}

/*!
 * Uses the stream's << operator to write the count and then all objects.
 *
 * \warning The function depends on the type having the operator << defined, which takes an std::ostream& and writes it's data to it. Return type doesn't matter.
 * \note Best used with std::cout or text std::ofstream
 */
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const List<T>& obj) {
	ostr << obj.get_count() << std::endl;
	for (int i = 0; i < obj.get_count(); i++)
		ostr << obj[i];

	return ostr;
}


#endif
