#ifndef HEADER_ORDEREDLIST
#define HEADER_ORDEREDLIST

#include "List.h"

template <class T>
class OrderedList : public List<T> {
public:
	OrderedList(const T* elements, unsigned elementsCount);

	void add(const T& element) = delete;
	bool insertAt(const T& element, unsigned index) = delete;

	bool insert(const T& element);
	// unsigned findIndex(const T& element) const; TODO: binary search
};

#endif
