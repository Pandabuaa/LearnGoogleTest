#pragma once
#include <iostream>
class Complex
{
friend	std::ostream& operator<<(std::ostream&, const Complex&);
friend bool operator==(const Complex&, const Complex&);
public:
	Complex() = default;
	// a+bi
	Complex(double i, double j) :a(i),b(j){

	}
	virtual Complex& add(const Complex&);
	virtual Complex& sub(const Complex&);
	virtual Complex& mul(const Complex&);
	virtual Complex& div(const Complex&);
	virtual Complex& operator+=(const Complex&);
	virtual Complex& operator-=(const Complex&);
	virtual Complex& operator*=(const Complex&);
	virtual Complex& operator/=(const Complex&);
//private:
	double a = 0;
	double b = 0;
};
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
bool operator==(const Complex&, const Complex&);
std::ostream& operator<<(std::ostream&, const Complex&);

