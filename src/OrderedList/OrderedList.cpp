#include "OrderedList.h"

bool OrderedList::insert(const T& element) {
	if (length == count) resize();

	unsigned l = 0, r = count - 1, m = l / 2 + r / 2;
	while (l < r) {
		if (elements[m].compare(element) > 0) r = m;
		else if (elements[m].compare(element) < 0) l = m;
		m = l / 2 + r / 2;
	}
}
