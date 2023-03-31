#include "Complex.h"
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
	double tempb = a * rhs.b + b + rhs.a;
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
std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << "(" << c.a << "+" << c.b << "i)";
	return os;
}
