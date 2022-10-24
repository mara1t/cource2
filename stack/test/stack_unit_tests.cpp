#include "stack_bool.h"
#include <gtest/gtest.h>

static const int size_for_test = 10000;

TEST(StackTest, test1)
{
    stack::Stack_t<int> mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(3, mystack.pop());
}

TEST(StackTest, test2)
{
    stack::Stack_t<int> mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(3, mystack.get_size());
}

TEST(StackTest, test3)
{
    stack::Stack_t<int> mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(10, mystack.get_capacity());
}

TEST(StackTest, test4)
{
    stack::Stack_t<bool> mystack {};
    mystack.push(1);
    mystack.push(0);
    mystack.push(1);
    EXPECT_EQ(1, mystack.pop());
}

TEST(StackTest, test5)
{
    stack::Stack_t<bool> mystack {};
    mystack.push(1);
    mystack.push(1);
    mystack.push(1);
    EXPECT_EQ(3, mystack.get_size());
}

TEST(StackTest, test6)
{
    stack::Stack_t<bool> mystack {};
    mystack.push(1);
    mystack.push(0);
    mystack.push(1);
    EXPECT_EQ(sizeof(int) * 8, mystack.get_capacity());
}

TEST(StackTest, test7)
{
    stack::Stack_t<int> mystack {};
    for (int iter = 0; iter < size_for_test; iter++) {
        mystack.push(2 * iter);
    }
    EXPECT_EQ(size_for_test, mystack.get_size());
}

TEST(StackTest, test8)
{
    stack::Stack_t<bool> mystack {};
    for (int iter = 0; iter < size_for_test; iter++) {
        mystack.push(iter % 2);
    }
    EXPECT_EQ(size_for_test, mystack.get_size());
}

TEST(StackTest, test9)
{
    stack::Stack_t<bool> mystack {};
    for (int iter = 0; iter < size_for_test; iter++) {
        mystack.push(iter % 2);
    }
    EXPECT_EQ(size_for_test, mystack.get_size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}