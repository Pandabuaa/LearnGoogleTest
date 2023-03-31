#pragma once
#include<iostream>
template<typename T>class Item
{
private:
	T coeff;
	int index;
};
template<typename T> Item<T> operator+(Item<T>& ,Item<T>&);
template<typename T> Item<T> operator*(Item<T>&, Item<T>&);
template<typename T> std::ostream& operator<<(std::ostream&,Item<T>&);
