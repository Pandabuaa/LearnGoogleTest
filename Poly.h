#pragma once
#include <vector>
#include "Item.h"
template<typename T> class Poly
{
public:
	Poly(Item t) {
		items.push_back(t);
	}
private:
	std::vector<Item<T>> items;
};
template<typename T> Poly<T> operator+(Poly<T>&, Poly<T>&);
template<typename T> Poly<T> operator*(Poly<T>&, Poly<T>&);



