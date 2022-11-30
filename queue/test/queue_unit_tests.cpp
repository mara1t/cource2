#include "queue.h"
#include <gtest/gtest.h>

static const int size_for_test = 10000;

using params = ::testing::Types<queue::queue_t<int>, queue::queue_stck_t<int>>;

template <typename T>
class QueueTest : public ::testing::Test {
    using MyParamType = T;
};

TYPED_TEST_SUITE(QueueTest, params);

TYPED_TEST(QueueTest, test_pop)
{
    TypeParam mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    ASSERT_EQ(1, mystack.pop());
    ASSERT_EQ(2, mystack.pop());
    ASSERT_EQ(3, mystack.pop());
}

TYPED_TEST(QueueTest, test_get_size)
{
    TypeParam mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    ASSERT_EQ(3, mystack.get_size());
    ASSERT_EQ(1, mystack.pop());
    ASSERT_EQ(2, mystack.pop());
    ASSERT_EQ(3, mystack.pop());
}

TYPED_TEST(QueueTest, test_capacity)
{
    TypeParam mystack {};
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    ASSERT_EQ(1, mystack.pop());
    ASSERT_EQ(2, mystack.pop());
    ASSERT_EQ(3, mystack.pop());
}

TYPED_TEST(QueueTest, test_big_size)
{
    TypeParam mystack {};
    for (int iter = 0; iter < size_for_test; iter++) {
        mystack.push(2 * iter);
    }
    EXPECT_EQ(size_for_test, mystack.get_size());
}

TYPED_TEST(QueueTest, test_pop_last_elem)
{
    TypeParam mystack {};
    for (int iter = 0; iter <= 1000000; iter++) {
        mystack.push(iter);
    }
    EXPECT_EQ(0, mystack.pop());
}

TYPED_TEST(QueueTest, test_big_data_pop_all_elem)
{
    TypeParam mystack {};
    for (int iter = 0; iter < 1000000; iter++) {
        mystack.push(iter);
    }
    for (int iter = 0; iter < 1000000; iter++) {
        EXPECT_EQ(mystack.pop(), iter);
    }
}

TYPED_TEST(QueueTest, test_copy_lvalue)
{
    TypeParam rstack;
    for (int i = 0; i < size_for_test; ++i) {
        rstack.push(i);
    }
    TypeParam lstack {rstack};
    ASSERT_EQ(lstack.get_size(), rstack.get_size());
    for (int i = 0; i < size_for_test; ++i) {
        ASSERT_EQ(lstack.pop(), rstack.pop());
    }
    ASSERT_EQ(lstack.get_size(), 0);
    ASSERT_EQ(rstack.get_size(), 0);
}

TYPED_TEST(QueueTest, test_empty)
{
    TypeParam stack;
    ASSERT_EQ(stack.is_empty(), 1);
}

TYPED_TEST(QueueTest, test_not_empty)
{
    TypeParam stack;
    stack.push(1);
    ASSERT_EQ(stack.is_empty(), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}