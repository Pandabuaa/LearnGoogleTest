#include"Complex.h"
#include "Item.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
class MockComplex :public Complex{
public:
	MOCK_METHOD(Complex&, add, (const Complex&), (override));
	MOCK_METHOD(Complex&, sub, (const Complex&), (override));
	MOCK_METHOD(Complex&, mul, (const Complex&), (override));
	MOCK_METHOD(Complex&, div, (const Complex&), (override));
};

TEST(ItemTest, SelfAdd) {
	MockComplex complex;
	EXPECT_CALL(complex, add(complex))
		.Times(1);
	Item<Complex> t1(complex,2);
	t1 += t1;
}