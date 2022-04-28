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
void List<T>::add(const T& element) {
	if (length == count) resize();

	elements[count++] = element;
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