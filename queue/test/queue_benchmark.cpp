#include <benchmark/benchmark.h>
#include "queue.h"
#include <chrono>
#include <string>

template <typename Type>
void bench1(int size)
{
    Type myqueue {};
    for (int iter = 0; iter < size; iter++) {
        myqueue.push(iter);
        myqueue.pop();
    }
}

// insert in queue
template <typename Type>
void bench2(int size)
{
    const int insert_elem = 10;
    Type myqueue {};
    for (int iter = 0; iter < size; iter++) {
        myqueue.push(iter);
    }
    for (int iter = 0; iter < size * 3 / 2; iter++) {
        myqueue.insert(insert_elem, iter);
    }
}

template <typename Type>
static void test1(benchmark::State &state)
{   
    const int big_size_queue = 1000000;
    for (auto _ : state) {
        bench1<Type>(big_size_queue);
    }
}

template <typename Type>
static void test2(benchmark::State &state)
{
    const int size_for_insert =  10000;
    for (auto _ : state) {
        bench2<Type>(size_for_insert);
    }
}

BENCHMARK_TEMPLATE(test1, queue::queue_t<int>);
BENCHMARK_TEMPLATE(test1, queue::queue_stck_t<int>);
BENCHMARK_TEMPLATE(test2, queue::queue_t<int>);
BENCHMARK_TEMPLATE(test2, queue::queue_stck_t<int>);

// Run the benchmark
BENCHMARK_MAIN();
