#include <gtest/gtest.h>
#include "Complex.h"
#include "BigInteger.h"
#include "Item.h"
#include "Poly.h"
#include <iostream> 
int main(int argc,char* argv[]){
    Complex c1(1,2);
    Complex c2(3, 4);
    std::cout << "c1:" << c1 << std::endl;
    std::cout << "c2:" << c2 << std::endl;
    std::cout << "c1+c2" << c1+c2 << std::endl;
    std::cout << "c1-c2" << c1-c2 << std::endl;
    std::cout << "c1*c2" << c1*c2 << std::endl;
    std::cout << "c1/c2" << c1/c2 << std::endl;

    BigInteger b1;
    BigInteger b2("12345678910");
    BigInteger b3 = "-12345678910";
    BigInteger b4("100");
    std::cout << "b1:" << b1 << std::endl;
    std::cout << "b2:" << b2 << std::endl;
    std::cout << "b3:" << b3 << std::endl;
    std::cout << "b2+b3:" << b2+b3 << std::endl;
    std::cout << "b2-b3:" << b2-b3 << std::endl;
    std::cout << "b3-b2:" << b3 - b2 << std::endl;
    std::cout << "b2*b3:" << b2 * b3 << std::endl;
    std::cout << "b4^2" << b4 * b4 << std::endl;

    Item<double> t1;
    Item<Complex> t2;
    Item<BigInteger> t3;
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;
    Item<double> t5(3, 2);
    Item<double> t6(1, 1);
    Item<double> t7(4, 0);
    std::cout << t5 * t6 << std::endl;
    Poly<double> p1 = {t5,t6,t7};
    std::cout << p1 << std::endl;
    std::cout << "p1+p1:" << p1 + p1 << std::endl;
    std::cout << "p1*p1:" << p1 * p1 << std::endl;
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
