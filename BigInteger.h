#pragma once
#include <vector>
#include <string>
#include <iostream>
enum flag {
	NEG,
	POS
};
class BigInteger
{
friend	bool absless(const BigInteger&, const BigInteger&);
friend	BigInteger operator+ (const BigInteger&, const BigInteger&);
friend	BigInteger operator- (const BigInteger&, const BigInteger&);
friend BigInteger operator* (const BigInteger&, const BigInteger&);
friend std::ostream& operator<<(std::ostream&, const BigInteger&);
public:
	BigInteger() {
		f = POS;
		nums.push_back(0);
	}
	BigInteger(std::string s);
private:
	flag f;
	std::vector<int> nums;
};
BigInteger operator+ (const BigInteger&,const BigInteger&);
BigInteger operator- (const BigInteger&, const BigInteger&);
BigInteger operator* (const BigInteger&, const BigInteger&);
std::ostream& operator<<(std::ostream&, const BigInteger&);
bool absless(const BigInteger&, const BigInteger&);

