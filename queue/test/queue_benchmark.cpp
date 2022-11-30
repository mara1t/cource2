#include <benchmark/benchmark.h>
#include "queue.h"
#include <chrono>
#include <string>

template<typename Type>
void bench1(int size) {
    Type myqueue {};
    for (int iter = 0; iter < size; iter++) {
        myqueue.push(iter);
        myqueue.pop();
    }
}

//insert in queue
template<typename Type>
void bench2(int size) {
    Type myqueue {};
    for (int iter = 0; iter < size; iter++) {
        myqueue.push(iter);
    }
    for (int iter = 0; iter < size - 1; iter++) {
        myqueue.insert(static_cast<int>(10), iter);
    }   
}

template<typename Type>
static void test1(benchmark::State& state) {
    for (auto _ : state) {
        bench1<Type>(1000000);
    }
}

template<typename Type>
static void test2(benchmark::State& state) {
    for (auto _ : state) {
        bench2<Type>(10000);
    }
}


BENCHMARK_TEMPLATE(test1, queue::queue_t<int>);
BENCHMARK_TEMPLATE(test1, queue::queue_stck_t<int>);
BENCHMARK_TEMPLATE(test2, queue::queue_t<int>);
BENCHMARK_TEMPLATE(test2, queue::queue_stck_t<int>);

// Run the benchmark
BENCHMARK_MAIN();

