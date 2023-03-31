# 搭建googletest环境
1. 创建项目文件夹learngoogletest
```shell
mkdir learngoogletest
cd learngoogletest
```

2. googletest源码安装
```shell
git clone https://github.com/google/googletest.git -b v1.13.0
cd googletest        # Main directory of the cloned repository.
mkdir build          # Create a directory to hold the build output.
cd build
cmake ..             # Generate native build scripts for GoogleTest.
```

3. 配置VS工程的cmake文件

项目CMakeLists.txt内容为：
```cmake
# cmake的最小版本号，设置项目的cmake最低要求版本
cmake_minimum_required(VERSION 3.12) 

# 项目名称
project(learngtest)


set(GTEST_DIR ".\\googletest")
find_library(gtest gtest HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gtest_main gtest_main HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gmock gmock HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gmock_main gmock_main HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
set(googletest ${gtest} ${gtest_main} ${gmock} ${gmock_main})

include_directories("${GTEST_DIR}\\googletest\\include")
include_directories("${GTEST_DIR}\\googlemock\\include")

aux_source_directory(. ALL_SRCS)
add_executable(mytest ${ALL_SRCS})

target_link_libraries(mytest ${googletest})
```
编写测试文件内容
```cpp
#include <gtest/gtest.h>
#include "myfunc.h"
TEST(myfunc,add)
{
    GTEST_ASSERT_EQ(add(1,2),3);
}
int main(int argc,char* argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

```
```cpp
int add(int a,int b){
    return a+b;
}
```
此时项目文件内容为
```
└─learngoogletest/
	├─ googletest/
  ├─ mytest.cpp
  ├─ myfunc.h
  └─ CMakeLists.txt
```

4. 创建build文件夹执行cmake命令

完成后打开build文件夹的learngoogletest.sln即可运行项目。如图为运行结果：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/34859586/1680074820210-f019ccac-bada-4b05-a733-b361aac00ad8.png#averageHue=%232c2c2c&clientId=uc149f8f0-16ef-4&from=paste&height=277&id=uf2916af8&name=image.png&originHeight=277&originWidth=791&originalType=binary&ratio=1&rotation=0&showTitle=false&size=14063&status=done&style=none&taskId=u7a5c75e6-7d10-4926-8f6b-7f1732ca0f5&title=&width=791)
# gtest相关用法
## 使用TEST()宏来定义测试函数
```
TEST(TestSuiteName, TestName) {
  ... test body ...
}
```
一个程序将包含若干test suite，一个test suite包含若干test。按照被测代码的结构，逻辑相关的若干test应该放在一个test suite中。
test body部分为任意有效的C++语句以及各式的google test断言。
断言包含两大类：ASSERT_*和EXPECT_*.
ASSERT_*失败时会生成fatal failures并中止程序。
EXPECT_*失败时会生成nonfatal failures,不会中止程序。
我们更倾向于使用EXPECT_*，这样可以生成更多的报错信息。而如果报错后测试没有继续执行的意义了，我们使用ASSERT_*。
当断言失败后，Googletest会打印断言源文件，行号和错误信息，也可以附加自定义的报错信息。
例一：官方sample1
```cpp
// A sample program demonstrating using Google C++ testing framework.

#include "sample1.h"

// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
int Factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

// Returns true if and only if n is a prime number.
bool IsPrime(int n) {
    // Trivial case 1: small numbers
    if (n <= 1) return false;

    // Trivial case 2: even numbers
    if (n % 2 == 0) return n == 2;

    // Now, we have that n is odd and n >= 3.

    // Try to divide n by every odd number i, starting from 3
    for (int i = 3;; i += 2) {
        // We only have to try i up to the square root of n
        if (i > n / i) break;

        // Now, we have i <= n/i < n.
        // If n is divisible by i, n is not prime.
        if (n % i == 0) return false;
    }

    // n has no integer factor in the range (1, n), and thus is prime.
    return true;
}
```
```cpp
#include "sample1.h"

#include <limits.h>

#include "gtest/gtest.h"
namespace {
// Tests Factorial().

// Tests factorial of negative numbers.
TEST(FactorialTest, Negative) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_EQ(1, Factorial(-5));
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_GT(Factorial(-10), 0);
}

// Tests factorial of 0.
TEST(FactorialTest, Zero) { EXPECT_EQ(1, Factorial(0)); }

// Tests factorial of positive numbers.
TEST(FactorialTest, Positive) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}

// Tests IsPrime()

// Tests negative input.
TEST(IsPrimeTest, Negative) {
  // This test belongs to the IsPrimeTest test case.

  EXPECT_FALSE(IsPrime(-1));
  EXPECT_FALSE(IsPrime(-2));
  EXPECT_FALSE(IsPrime(INT_MIN));
}

// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
  EXPECT_FALSE(IsPrime(0));
  EXPECT_FALSE(IsPrime(1));
  EXPECT_TRUE(IsPrime(2));
  EXPECT_TRUE(IsPrime(3));
}

// Tests positive input.
TEST(IsPrimeTest, Positive) {
  EXPECT_FALSE(IsPrime(4));
  EXPECT_TRUE(IsPrime(5));
  EXPECT_FALSE(IsPrime(6));
  EXPECT_TRUE(IsPrime(23));
}
}  // namespace
```
该测试程序包含两个test suite，分别对应两个待测的函数。每个test suite又包含若干test，分情况讨论实现测试的完备性。
![image.png](https://cdn.nlark.com/yuque/0/2023/png/34859586/1680145701070-f3a55eab-8a6e-4714-a684-981b8fcbdc70.png#averageHue=%23161616&clientId=u61b58ecc-c0ed-4&from=paste&height=296&id=u8f294368&name=image.png&originHeight=296&originWidth=466&originalType=binary&ratio=1&rotation=0&showTitle=false&size=10369&status=done&style=none&taskId=uf4b057eb-c03d-40ab-a73e-f8c9fb1bde0&title=&width=466)
## 使用TEST_F()宏来定义测试函数
当一个test suite中的多个test需要共享对象和子程序时，可以将它们放置在一个test fixture类中。
定义一个fixture类：

1. 继承::testing::Test，声明访问权限为protected，便于子类访问fixture类的成员。
2. 在类内声明将要用到的对象
3. 使用override关键字重写SetUp()函数，该函数在类构造之后做一些初始化工作
4. 如果需要的话重写TearDown()函数，释放在SetUp()函数中申请的资源
5. 如果需要的话编写一些帮助测试的子程序。

使用TEST_F()而不是TEST()来访问test fixture类中的对象和子程序：
```cpp
TEST_F(TestFixtureClassName, TestName) {
  ... test body ...
}
```
对于同一个test suite的不同test，每次都将重新创建一个test fixture对象，因此不同test之间不会相互影响。
例二：官方的sample3
```cpp
#ifndef GOOGLETEST_SAMPLES_SAMPLE3_INL_H_
#define GOOGLETEST_SAMPLES_SAMPLE3_INL_H_

#include <stddef.h>

// Queue is a simple queue implemented as a singled-linked list.
//
// The element type must support copy constructor.
template <typename E>  // E is the element type
class Queue;

// QueueNode is a node in a Queue, which consists of an element of
// type E and a pointer to the next node.
template <typename E>  // E is the element type
class QueueNode {
friend class Queue<E>;

public:
// Gets the element in this node.
const E& element() const { return element_; }

// Gets the next node in the queue.
QueueNode* next() { return next_; }
const QueueNode* next() const { return next_; }

private:
// Creates a node with a given element value.  The next pointer is
// set to NULL.
explicit QueueNode(const E& an_element)
: element_(an_element), next_(nullptr) {}

// We disable the default assignment operator and copy c'tor.
const QueueNode& operator=(const QueueNode&);
QueueNode(const QueueNode&);

E element_;
QueueNode* next_;
};

template <typename E>  // E is the element type.
class Queue {
public:
// Creates an empty queue.
Queue() : head_(nullptr), last_(nullptr), size_(0) {}

// D'tor.  Clears the queue.
~Queue() { Clear(); }

// Clears the queue.
void Clear() {
if (size_ > 0) {
// 1. Deletes every node.
QueueNode<E>* node = head_;
QueueNode<E>* next = node->next();
for (;;) {
delete node;
node = next;
if (node == nullptr) break;
next = node->next();
}

// 2. Resets the member variables.
head_ = last_ = nullptr;
size_ = 0;
}
}

// Gets the number of elements.
size_t Size() const { return size_; }

// Gets the first element of the queue, or NULL if the queue is empty.
QueueNode<E>* Head() { return head_; }
const QueueNode<E>* Head() const { return head_; }

// Gets the last element of the queue, or NULL if the queue is empty.
QueueNode<E>* Last() { return last_; }
const QueueNode<E>* Last() const { return last_; }

// Adds an element to the end of the queue.  A copy of the element is
// created using the copy constructor, and then stored in the queue.
// Changes made to the element in the queue doesn't affect the source
// object, and vice versa.
void Enqueue(const E& element) {
QueueNode<E>* new_node = new QueueNode<E>(element);

if (size_ == 0) {
head_ = last_ = new_node;
size_ = 1;
} else {
last_->next_ = new_node;
last_ = new_node;
size_++;
}
}

// Removes the head of the queue and returns it.  Returns NULL if
// the queue is empty.
E* Dequeue() {
if (size_ == 0) {
return nullptr;
}

const QueueNode<E>* const old_head = head_;
head_ = head_->next_;
size_--;
if (size_ == 0) {
last_ = nullptr;
}

E* element = new E(old_head->element());
delete old_head;

return element;
}

// Applies a function/functor on each element of the queue, and
// returns the result in a new queue.  The original queue is not
// affected.
template <typename F>
Queue* Map(F function) const {
Queue* new_queue = new Queue();
for (const QueueNode<E>* node = head_; node != nullptr;
node = node->next_) {
new_queue->Enqueue(function(node->element()));
}

return new_queue;
}

private:
QueueNode<E>* head_;  // The first node of the queue.
QueueNode<E>* last_;  // The last node of the queue.
size_t size_;         // The number of elements in the queue.

// We disallow copying a queue.
Queue(const Queue&);
const Queue& operator=(const Queue&);
};

#endif  // GOOGLETEST_SAMPLES_SAMPLE3_INL_H_

```
```cpp
#include "sample3-inl.h"
#include "gtest/gtest.h"
namespace {
// To use a test fixture, derive a class from testing::Test.
class QueueTestSmpl3 : public testing::Test {
protected:  // You should make the members protected s.t. they can be
// accessed from sub-classes.
// virtual void SetUp() will be called before each test is run.  You
// should define it if you need to initialize the variables.
// Otherwise, this can be skipped.
void SetUp() override {
q1_.Enqueue(1);
q2_.Enqueue(2);
q2_.Enqueue(3);
}

// virtual void TearDown() will be called after each test is run.
// You should define it if there is cleanup work to do.  Otherwise,
// you don't have to provide it.
//
// virtual void TearDown() {
// }

// A helper function that some test uses.
static int Double(int n) { return 2 * n; }

// A helper function for testing Queue::Map().
void MapTester(const Queue<int>* q) {
// Creates a new queue, where each element is twice as big as the
// corresponding one in q.
const Queue<int>* const new_q = q->Map(Double);

// Verifies that the new queue has the same size as q.
ASSERT_EQ(q->Size(), new_q->Size());

// Verifies the relationship between the elements of the two queues.
for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head();
n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
EXPECT_EQ(2 * n1->element(), n2->element());
}

delete new_q;
}

// Declares the variables your tests want to use.
Queue<int> q0_;
Queue<int> q1_;
Queue<int> q2_;
};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests the default c'tor.
TEST_F(QueueTestSmpl3, DefaultConstructor) {
// You can access data in the test fixture here.
EXPECT_EQ(0u, q0_.Size());
}

// Tests Dequeue().
TEST_F(QueueTestSmpl3, Dequeue) {
int* n = q0_.Dequeue();
EXPECT_TRUE(n == nullptr);

n = q1_.Dequeue();
ASSERT_TRUE(n != nullptr);
EXPECT_EQ(1, *n);
EXPECT_EQ(0u, q1_.Size());
delete n;

n = q2_.Dequeue();
ASSERT_TRUE(n != nullptr);
EXPECT_EQ(2, *n);
EXPECT_EQ(1u, q2_.Size());
delete n;
}

// Tests the Queue::Map() function.
TEST_F(QueueTestSmpl3, Map) {
MapTester(&q0_);
MapTester(&q1_);
MapTester(&q2_);
}
}  // namespace

```
测试结果
![image.png](https://cdn.nlark.com/yuque/0/2023/png/34859586/1680147711828-fbec2d5b-01cf-4aa4-92e9-5a1d68e12f6c.png#averageHue=%23191919&clientId=u61b58ecc-c0ed-4&from=paste&height=152&id=uf52e4873&name=image.png&originHeight=152&originWidth=437&originalType=binary&ratio=1&rotation=0&showTitle=false&size=5952&status=done&style=none&taskId=ud6f763cb-a944-4236-98a6-8d689579225&title=&width=437)
# gmock相关用法
## demo说明

1. 多项式：形如$a_0+a_1x+a_2x^2+\dots+a_nx^n$为多项式，多项式之间可以进行加法和乘法。
2. 多项式的每一项由未知数$x$，系数$a_n$，指数构成。
3. 我们规定，系数可以为浮点数，大整数，复数；指数为自然数。

