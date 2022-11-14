#include "stack_bool.h"
#include <gtest/gtest.h>

static const int size_for_test = 10000;

TEST(StackTest, test_pop)
{
    stack::Stack_t<int> mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(3, mystack.pop());
}

TEST(StackTest, test_get_size)
{
    stack::Stack_t<int> mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(3, mystack.get_size());
}

TEST(StackTest, test_capacity)
{
    stack::Stack_t<int> mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(10, mystack.get_capacity());
}

TEST(StackTest, test_bool_pop)
{
    stack::Stack_t<bool> mystack {};
    mystack.push(1);
    mystack.push(0);
    mystack.push(1);
    EXPECT_EQ(1, mystack.pop());
}

TEST(StackTest, test_bool_size)
{
    stack::Stack_t<bool> mystack {};
    mystack.push(1);
    mystack.push(1);
    mystack.push(1);
    EXPECT_EQ(3, mystack.get_size());
}

TEST(StackTest, test_bool_capacity)
{
    stack::Stack_t<bool> mystack {};
    mystack.push(1);
    mystack.push(0);
    mystack.push(1);
    EXPECT_EQ(sizeof(int) * 8, mystack.get_capacity());
}

TEST(StackTest, test_big_size)
{
    stack::Stack_t<int> mystack {};
    for (int iter = 0; iter < size_for_test; iter++) {
        mystack.push(2 * iter);
    }
    EXPECT_EQ(size_for_test, mystack.get_size());
}

TEST(StackTest, test_bool_big_size)
{
    stack::Stack_t<bool> mystack {};
    for (int iter = 0; iter < size_for_test; iter++) {
        mystack.push(iter % 2);
    }
    EXPECT_EQ(size_for_test, mystack.get_size());
}

TEST(StackTest, test_pop_last_elem)
{
    stack::Stack_t<int> mystack {};
    for (int iter = 0; iter <= 1000000; iter++) {
        mystack.push(iter);
    }
    EXPECT_EQ(1000000, mystack.pop());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}