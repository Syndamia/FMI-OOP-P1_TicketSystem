#ifndef HEADER_ORDEREDLIST
#define HEADER_ORDEREDLIST

#include "List.hpp"

template <class T>
class OrderedList : public List<T> {
public:
	OrderedList();
	OrderedList(const T* elements, unsigned elementsCount);

	void add(T element) = delete;
	void insertAt(T element, unsigned index) = delete;

	void insert(T element);
	// unsigned findIndex(const T& element) const; TODO: binary search
};

template <class T>
OrderedList<T>::OrderedList() : OrderedList(nullptr, 0) {}

template <class T>
OrderedList<T>::OrderedList(const T* elements, unsigned elementsCount) : List<T>::List(elements, elementsCount) {}

template <class T>
void OrderedList<T>::insert(T element) {
	if (List<T>::length == List<T>::count) List<T>::resize();

	unsigned insertionInd = 0;
	while (insertionInd < List<T>::count && List<T>::elements[insertionInd].compare(element) < 0)
		insertionInd++;

	List<T>::insertAt(element, insertionInd);
}

#endif
