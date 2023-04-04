#include "BigInteger.h"
#include <gmock/gmock.h>
class BigIntegerCal {
	virtual BigInteger add(const BigInteger& lhs, const BigInteger& rhs) {
		return lhs + rhs;
	}

	virtual BigInteger sub(const BigInteger& lhs, const BigInteger& rhs) {
		return lhs - rhs;
	}

	virtual BigInteger mul(const BigInteger& lhs, const BigInteger& rhs) {
		return lhs * rhs;
	}
};

class MockBigInteger :public BigIntegerCal {
	MOCK_METHOD(BigInteger, add, (const BigInteger& lhs, const BigInteger& rhs), (override));
	MOCK_METHOD(BigInteger, sub, (const BigInteger& lhs, const BigInteger& rhs), (override));
	MOCK_METHOD(BigInteger, mul, (const BigInteger& lhs, const BigInteger& rhs), (override));
};