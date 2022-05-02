#include "OrderedList.h"

template <class T>
OrderedList<T>::OrderedList() : OrderedList(nullptr, 0) {}

template <class T>
OrderedList<T>::OrderedList(const T* elements, unsigned elementsCount) : List<T>::List(elements, elementsCount) {}

template <class T>
bool OrderedList<T>::insert(const T& element) {
	if (List<T>::length == List<T>::count) List<T>::resize();

	unsigned insertionInd = 0;
	while (List<T>::elements[insertionInd].compare(element) < 0 && insertionInd < List<T>::count)
		insertionInd++;

	return List<T>::insertAt(element, insertionInd);
}
