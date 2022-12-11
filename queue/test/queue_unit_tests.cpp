#include "queue.h"
#include <gtest/gtest.h>

const int size_for_test = 10000;
const int big_size_for_test = 1000000;

using params = ::testing::Types<queue::queue_t<int>, queue::queue_stck_t<int>, queue::queue_t<double>, queue::queue_stck_t<double>>;
//using bool_param = 

template <typename T>
class QueueTest : public ::testing::Test {
    using MyParamType = T;
};

TYPED_TEST_SUITE(QueueTest, params);

TYPED_TEST(QueueTest, test_pop)
{
    TypeParam queue {};
    queue.push(1);
    queue.push(2);
    queue.push(3);
    ASSERT_EQ(1, queue.pop());
    ASSERT_EQ(2, queue.pop());
    ASSERT_EQ(3, queue.pop());
}

TYPED_TEST(QueueTest, test_get_size)
{
    TypeParam queue {};
    queue.push(1);
    queue.push(2);
    queue.push(3);
    ASSERT_EQ(3, queue.get_size());
    ASSERT_EQ(1, queue.pop());
    ASSERT_EQ(2, queue.pop());
    ASSERT_EQ(3, queue.pop());
}

TYPED_TEST(QueueTest, test_capacity)
{
    TypeParam queue {};
    queue.push(1);
    queue.push(2);
    queue.push(3);
    ASSERT_EQ(1, queue.pop());
    ASSERT_EQ(2, queue.pop());
    ASSERT_EQ(3, queue.pop());
}

TYPED_TEST(QueueTest, test_big_size)
{
    TypeParam queue {};
    for (int iter = 0; iter < size_for_test; iter++) {
        queue.push(2 * iter);
    }
    EXPECT_EQ(size_for_test, queue.get_size());
}

TYPED_TEST(QueueTest, test_pop_last_elem)
{
    TypeParam queue {};
    for (int iter = 0; iter <= big_size_for_test; iter++) {
        queue.push(iter);
    }
    EXPECT_EQ(0, queue.pop());
}

TYPED_TEST(QueueTest, test_big_data_pop_all_elem)
{
    TypeParam queue {};
    for (int iter = 0; iter < big_size_for_test; iter++) {
        queue.push(iter);
    }
    for (int iter = 0; iter < big_size_for_test; iter++) {
        EXPECT_EQ(queue.pop(), iter);
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
    TypeParam queue;
    ASSERT_EQ(queue.is_empty(), 1);
}

TYPED_TEST(QueueTest, test_not_empty)
{
    TypeParam queue;
    queue.push(1);
    ASSERT_EQ(queue.is_empty(), 0);
}

TEST(BoolQueue, test_big_data_pop_all_elem)
{
    queue::queue_stck_t<bool> queue {};
    for (int iter = 0; iter < big_size_for_test; iter++) {
        queue.push(iter % 2);
    }
    for (int iter = 0; iter < big_size_for_test; iter++) {
        EXPECT_EQ(queue.pop(), iter % 2);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}