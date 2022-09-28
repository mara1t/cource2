#include "stack_bool.h"
#include "stack.h"
#include <gtest/gtest.h>

TEST(StackTest, test1) {
    stack::Stack_t<int> mystack{};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(3, mystack.pop());
}

TEST(StackTest, test2) {
    stack::Stack_t<int> mystack{};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(3, mystack.get_size());
}

TEST(StackTest, test3) {
    stack::Stack_t<int> mystack{};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    EXPECT_EQ(10, mystack.get_capacity());
}

TEST(StackTest, test4) {
    stack::Stack_t<bool> mystack{};
    mystack.push(1);
    mystack.push(0);
    mystack.push(1);
    EXPECT_EQ(1, mystack.pop());
}

TEST(StackTest, test5) {
    stack::Stack_t<bool> mystack{};
    mystack.push(1);
    mystack.push(1);
    mystack.push(1);
    EXPECT_EQ(3, mystack.get_size());
}

TEST(StackTest, test6) {
    stack::Stack_t<bool> mystack{};
    mystack.push(1);
    mystack.push(0);
    mystack.push(1);
    EXPECT_EQ(sizeof(int) * 8, mystack.get_capacity());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}