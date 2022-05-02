#ifndef HEADER_ORDEREDLIST
#define HEADER_ORDEREDLIST

#include "../List/List.h"

template <class T>
class OrderedList : public List<T> {
public:
	void add(const T& element) = delete;
	bool insertAt(const T& element, unsigned index) = delete;

	bool insert(const T& element);
};

#endif
