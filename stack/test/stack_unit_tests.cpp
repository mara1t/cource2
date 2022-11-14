#include "stack.h"
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

TEST(StackTest, test_pop_all_elem)
{
    stack::Stack_t<int> mystack {};
    for (int iter = 0; iter <= 1000000; iter++) {
        mystack.push(iter);
    }
    for (int iter = 1000000; iter >= 0; iter--) {
        ASSERT_EQ(mystack.pop(), iter);
    }
}

TEST(StackTest, test_bool_pop_all_elem)
{
    stack::Stack_t<bool> mystack {};
    for (int iter = 0; iter <= 1000000; iter++) {
        mystack.push(iter % 2);
    }
    for (int iter = 1000000; iter >= 0; iter--) {
        ASSERT_EQ(mystack.pop(), iter % 2);
    }
}

TEST(StackTest, test_copy_lvalue)
{
    stack::Stack_t<int> rstack;
    for (int i = 0; i < size_for_test; ++i) {
        rstack.push(i);
    }
    stack::Stack_t<int> lstack{rstack};
    ASSERT_EQ(lstack.get_size(), rstack.get_size());
    ASSERT_EQ(lstack.get_capacity(), rstack.get_capacity());
    for (int i = 0; i < size_for_test; ++i) {
        ASSERT_EQ(lstack.pop(), rstack.pop());
    }
    ASSERT_EQ(lstack.get_size(), 0);
    ASSERT_EQ(rstack.get_size(), 0);
}

TEST(StackTest, test_bool_copy_lvalue)
{
    stack::Stack_t<bool> rstack;
    for (int i = 0; i < size_for_test; ++i) {
        rstack.push(i % 2);
    }
    stack::Stack_t<bool> lstack{rstack};
    ASSERT_EQ(lstack.get_size(), rstack.get_size());
    ASSERT_EQ(lstack.get_capacity(), rstack.get_capacity());

    for (int i = 0; i < size_for_test; ++i) {
        ASSERT_EQ(lstack.pop(), rstack.pop());
    }
    ASSERT_EQ(lstack.get_size(), 0);
    ASSERT_EQ(rstack.get_size(), 0);
}

TEST(StackTest, test_empty)
{
    stack::Stack_t<int> stack;
    ASSERT_EQ(stack.is_empty(), 1);
}

TEST(StackTest, test_bool_empty)
{
    stack::Stack_t<bool> stack;
    ASSERT_EQ(stack.is_empty(), 1);
}

TEST(StackTest, test_not_empty)
{
    stack::Stack_t<int> stack;
    stack.push(1);
    ASSERT_EQ(stack.is_empty(), 0);
}

TEST(StackTest, test_bool_not_empty)
{
    stack::Stack_t<bool> stack;
    stack.push(1);
    ASSERT_EQ(stack.is_empty(), 0);
}

TEST(StackTest, test_not_full)
{
    stack::Stack_t<int> stack;
    ASSERT_EQ(stack.is_full(), 0);
}

TEST(StackTest, test_bool_not_full)
{
    stack::Stack_t<bool> stack;
    ASSERT_EQ(stack.is_full(), 0);
}

TEST(StackTest, test_full)
{
    stack::Stack_t<int> stack;
    for (int i = 0; i < size_for_test; ++i) {
        rstack.push(i % 2);
    }
    ASSERT_EQ(stack.is_full(), 1);
}

TEST(StackTest, test_bool_full)
{
    stack::Stack_t<bool> stack;
    for (int i = 0; i < size_for_test; ++i) {
        rstack.push(i % 2);
    }
    ASSERT_EQ(stack.is_full(), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}