#include <gtest/gtest.h>
#include "Complex.h"
#include "BigInteger.h"
#include "Item.h"
#include "Poly.h"
#include <iostream> 
int main(int argc,char* argv[]){
    
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
