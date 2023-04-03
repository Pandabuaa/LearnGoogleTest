#include<gtest/gtest.h>
#include"Complex.h"
class ComplexTest : public ::testing::Test
{
protected:
	void SetUp() override {
		c1 = Complex(0.3, 0.4);
		c2 = Complex(0.1, 0.1);//delta
		c3 = Complex(0.4, 0.5);//add
		c4 = Complex(0.2, 0.3);//sub
		c5 = Complex(-0.01, 0.07);//mul
		c6 = Complex(3.5, 0.5);//div
	}
	Complex c1,c2,c3,c4,c5,c6;
};
TEST_F(ComplexTest, DefaultConstructor) {
	Complex c;
	EXPECT_EQ(c.a, 0);
	EXPECT_EQ(c.b, 0);
}

TEST_F(ComplexTest, CusteomConstructor) {
	double a = 3.1415926;
	double b = 2.71828;
	Complex c(a,b);
	EXPECT_EQ(c.a, a);
	EXPECT_EQ(c.b, b);
}

TEST_F(ComplexTest, SelfAdd) {
	c1 += c2;
	EXPECT_TRUE(c1==c3);
}

TEST_F(ComplexTest, SelfSub) {
	c1 -= c2;
	EXPECT_TRUE(c1== c4);
}

TEST_F(ComplexTest, SelfMul) {
	c1 *= c2;
	EXPECT_TRUE(c1==c5);
}

TEST_F(ComplexTest, SelfDiv) {
	c1 /= c2;
	EXPECT_TRUE(c1 == c6);
}

TEST_F(ComplexTest, Add) {
	EXPECT_TRUE(c1+c2 ==c3);
}

TEST_F(ComplexTest, Sub) {
	EXPECT_TRUE(c1-c2 == c4);
}

TEST_F(ComplexTest, Mul) {
	EXPECT_TRUE(c1*c2 == c5);
}

TEST_F(ComplexTest, Div) {
	EXPECT_TRUE(c1/c2 == c6);
}