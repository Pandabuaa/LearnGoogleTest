#include "Complex.h"
#include <cmath>
Complex& Complex::add(const Complex& rhs) {
	*this += rhs;
	return *this;
}
Complex& Complex::sub(const Complex& rhs) {
	*this -= rhs;
	return *this;
}
Complex& Complex::mul(const Complex& rhs) {
	*this *= rhs;
	return *this;
}
Complex& Complex::div(const Complex& rhs) {
	*this /= rhs;
	return *this;
}
Complex& Complex::operator+=(const Complex& rhs) {
	a += rhs.a;
	b += rhs.b;
	return *this;
}
Complex& Complex::operator-=(const Complex& rhs) {
	a -= rhs.a;
	b -= rhs.b;
	return *this;
}
Complex& Complex::operator*=(const Complex& rhs) {
	double tempa = a * rhs.a - b * rhs.b;
	double tempb = a * rhs.b + b * rhs.a;
	a = tempa;
	b = tempb;
	return *this;
}
Complex& Complex::operator/=(const Complex& rhs) {
	double tempa = (a * rhs.a + b * rhs.b) / (rhs.a * rhs.a + rhs.b * rhs.b);
	double tempb = (b * rhs.a - a * rhs.b) / (rhs.a * rhs.a + rhs.b * rhs.b);
	a = tempa;
	b = tempb;
	return *this;
}
Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res += rhs;
	return res;
}
Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res -= rhs;
	return res;
}
Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res *= rhs;
	return res;
}
Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex res = lhs;
	res /= rhs;
	
	return res;
}
bool operator==(const Complex& lhs, const Complex& rhs) {
	return fabs(lhs.a - rhs.a)<1e-6 && fabs(lhs.b - rhs.b)<1e-6;
}
std::ostream& operator<<(std::ostream& os, const Complex& c) {
	if (c.b >= 0) {
		os << "(" << c.a << "+" << c.b << "i)";
	}
	else {
		os << "(" << c.a  << c.b << "i)";
	}
	
	return os;
}
