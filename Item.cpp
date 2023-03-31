#include "Item.h"
#include <cassert>
template<typename T> Item<T> operator+(Item<T>& lhs, Item<T>& rhs) {
	Item<T> res;
	assert(lhs.index == rhs.index);
	res.coeff = lhs.coeff + rhs.coeff;
	res.index = lhs.index;
	return res;
}
template<typename T> Item<T> operator*(Item<T>& lhs, Item<T>& rhs) {
	Item<T> res;
	res.coeff = lhs.coeff * rhs.coeff;
	res.index = lhs.index + rhs.index;
	return res;
}
template<typename T> std::ostream& operator<<(std::ostream& os, Item<T>& t) {
	os << t.coeff <<"x^" << t.index;
}