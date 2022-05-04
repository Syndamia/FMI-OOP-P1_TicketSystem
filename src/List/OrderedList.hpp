#ifndef HEADER_ORDEREDLIST
#define HEADER_ORDEREDLIST

#include "List.hpp"

template <class T>
class OrderedList : public List<T> {
public:
	OrderedList();
	OrderedList(const T* elements, unsigned elementsCount);

	void add(const T& element) = delete;
	void insertAt(const T& element, unsigned index) = delete;

	void insert(const T& element);
	// unsigned findIndex(const T& element) const; TODO: binary search
};

template <class T>
OrderedList<T>::OrderedList() : OrderedList(nullptr, 0) {}

template <class T>
OrderedList<T>::OrderedList(const T* elements, unsigned elementsCount) : List<T>::List(elements, elementsCount) {}

template <class T>
void OrderedList<T>::insert(const T& element) {
	if (List<T>::length == List<T>::count) List<T>::resize();

	unsigned insertionInd = 0;
	while (List<T>::elements[insertionInd].compare(element) < 0 && insertionInd < List<T>::count)
		insertionInd++;

	List<T>::insertAt(element, insertionInd);
}

#endif
