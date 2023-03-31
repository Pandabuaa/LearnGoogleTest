#pragma once
#include <iostream>
class Complex
{
friend	std::ostream& operator<<(std::ostream&, const Complex&);
public:
	Complex() = default;
	// a+bi
	Complex(double i, double j) :a(i),b(j){

	}
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
private:
	double a;
	double b;
};
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
std::ostream& operator<<(std::ostream&, const Complex&);

