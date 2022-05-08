#ifndef HEADER_ORDEREDLIST
#define HEADER_ORDEREDLIST

/*! \file OrderedList.hpp
 *  \brief Stores declaration and definition of templated class OrderedList
 */

#include "List.hpp"

/*! \brief Inherits List, but contains it's elements in a sorted manner
 *
 * \warning Outside those defined in List, insert() requires the type to have defined a "compare" of functions.
 * \sa insert()
 */
template <typename T>
class OrderedList : public List<T> {
public:
	OrderedList();
	OrderedList(const T* elements, unsigned elementsCount);

	/*! \brief \warning Function is deleted, use insert() instead
	 * \sa insert()
	 */
	void add(T element) = delete;
	/*! \brief \warning Function is deleted, use insert() instead
	 * \sa insert()
	 */
	void insertAt(T element, unsigned index) = delete;

	//! Inserts an element at a sorted position
	void insert(T element);
};

template <typename T>
OrderedList<T>::OrderedList() : OrderedList(nullptr, 0) {}

template <typename T>
OrderedList<T>::OrderedList(const T* elements, unsigned elementsCount) : List<T>::List(elements, elementsCount) {}

/*!
  * \warning The function depends on the type having a function "compare" defined, which takes two elements and returns a number <0 if elem1 < elem2, >0 if elem1 > elem2, 0 if elem1 == elem2
  * \note Insertion is done linearly
 */
template <typename T>
void OrderedList<T>::insert(T element) {
	if (List<T>::length == List<T>::count) List<T>::resize();

	unsigned insertionInd = 0;
	while (insertionInd < List<T>::count && List<T>::elements[insertionInd].compare(element) < 0)
		insertionInd++;

	List<T>::insertAt(element, insertionInd);
}

#endif
