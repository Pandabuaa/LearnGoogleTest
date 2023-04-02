#pragma once



#include <vector>
#include<initializer_list>
#include "Item.h"
template<typename T> class Poly
{
	template<typename S> friend std::ostream& operator<<(std::ostream& os, const Poly<S>& p) {
		for (auto it = p.items.begin(); it != p.items.end(); it++) {
			os << "+" << *it;
		}
		return os;
	};
	template<typename S> friend   Poly<S> operator+(const Poly<S>& lhs, const Poly<S>& rhs) {
		Poly res = lhs;
		res += rhs;
		return res;
	};

	template<typename S> friend   Poly<S> operator*(const Poly<S>& lhs, const Item<S>& t) {
		Poly res = lhs;
		for (auto it = res.items.begin(); it != res.items.end(); it++) {
			*it *= t;
		}
		return res;
	};

	template<typename S>   friend Poly<S> operator*(const Poly<S>& lhs, const Poly<S>& rhs) {
		Poly res;
		for (auto it = rhs.items.begin(); it != rhs.items.end(); it++) {
			Poly temp = lhs * (*it);
			res += temp;
		}
		return res;
	};
public:
	Poly() { 
		Item<T> t;
		items.push_back(t); 
	}
	Poly(Item<T> t) {
		items.push_back(t);
	}
	Poly(std::initializer_list<Item<T>> il) {
		for (auto it = il.begin(); it != il.end(); it++) {
			items.push_back(*it);
		}
	}
	Poly<T>& operator+=(const Poly<T>& rhs) {
		auto lit = items.begin();
		auto rit = rhs.items.begin();
		while (lit != items.end() && rit != rhs.items.end()) {
			if (lit->index == rit->index) {
				*lit += *rit;
				lit++;
				rit++;
			}
			else if (lit->index > rit->index) {
				lit++;
			}
			else {
				//insert
				lit = items.insert(lit, *rit);
				lit++;
				rit++;
			}
		}
		while (rit != rhs.items.end()) {
			items.push_back(*rit);
		}
		return *this;
	}
	
private:
	std::vector<Item<T>> items;
};
//template<typename T> Poly<T> operator+(const Poly<T>&,const Poly<T>&);
//template<typename T> Poly<T> operator*(const Poly<T>&,const Item<T>&);
//template<typename T> Poly<T> operator*(const Poly<T>&,const Poly<T>&);
//template<typename T> std::ostream& operator<<(std::ostream&,const Poly<T>&);




