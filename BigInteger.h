#pragma once
#include <vector>
#include <string>
class BigInteger
{
friend	BigInteger operator+ (const BigInteger&, const BigInteger&);
friend	BigInteger operator- (const BigInteger&, const BigInteger&);
friend BigInteger operator* (const BigInteger&, const BigInteger&);

public:
	BigInteger() {
		nums.push_back(0);
	}
	BigInteger(std::string s);
private:
	std::vector<int> nums;
};
BigInteger operator+ (const BigInteger&,const BigInteger&);
BigInteger operator- (const BigInteger&, const BigInteger&);
BigInteger operator* (const BigInteger&, const BigInteger&);

