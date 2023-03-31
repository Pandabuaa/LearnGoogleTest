#include <gtest/gtest.h>
#include "myfunc.h"
/*
TEST(myfunc,add)
{
    ASSERT_EQ(add(1,2),3);
}
*/
int main(int argc,char* argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
