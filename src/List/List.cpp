#include "List.h"

/* Private */

template <class T>
void List<T>::resize() {
	length <<= 1;
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
List<T>::List(const T* elements, unsigned elementsCount) : List() {
	for (unsigned i = 0; i < elementsCount; i++)
		add(elements[i]);
}

template <class T>
void List<T>::add(const T& element) {
	if (length == count) resize();

	elements[count++] = element;
}

template <class T>
bool List<T>::insertAt(const T& element, unsigned index) {
	if (index >= count)
		return add(element);


}

template <class T>
bool List<T>::removeAt(unsigned index) {
	if (index >= count) return false;

	delete elements[index];
	for (int i = index; i < count; i++)
		elements[i] = elements[i + 1];
	elements[count--] = nullptr;
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
List<T>::List() {
	length = 8;
	count = 0;
	elements = new T[length];
}

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
