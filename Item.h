#pragma once

#include<iostream>
template<typename T>class Item
{
	friend std::ostream& operator<<(std::ostream& os, const Item<T>& t) {
		os << t.coeff << "x^" << t.index;
		return os;
	};
	friend  Item<T> operator+(Item<T>& lhs, Item<T>& rhs) {
		Item<T> res = lhs;
		res += rhs;
		return res;
	};
	friend Item<T> operator*(Item<T>& lhs, Item<T>& rhs) {
		Item<T> res = lhs;
		res *= rhs;
		return res;
	};
	

public:
	Item() :coeff(),index(0){}
	Item(T c,int i):coeff(c),index(i){}
	Item<T>& operator+=(const Item<T>& rhs) {
		coeff += rhs.coeff;
		return *this;
	}
	Item<T>& operator*=(const Item<T>& rhs) {
		coeff *= rhs.coeff;
		index += rhs.index;
		return *this;
	}
//private:
	T coeff;
	int index;
};
//template<typename T> Item<T> operator+(Item<T>& ,Item<T>&);
//template<typename T> Item<T> operator*(Item<T>&, Item<T>&);
//template<typename T> std::ostream& operator<<(std::ostream&,const Item<T>&);

