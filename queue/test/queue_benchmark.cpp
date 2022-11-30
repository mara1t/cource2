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
    /*for (size_t iter = 0; iter < size; iter++) {
        myqueue.pop();
    }*/
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
// Register the function as a benchmark
// BENCHMARK(BM_SomeFunction)->Arg(100000)->Arg(200000)->Arg(400000);

BENCHMARK_TEMPLATE(test1, queue::queue_t<int>);
BENCHMARK_TEMPLATE(test1, queue::queue_stck_t<int>);
BENCHMARK_TEMPLATE(test2, queue::queue_t<int>);
BENCHMARK_TEMPLATE(test2, queue::queue_stck_t<int>);
//BENCHMARK(BM_SomeFunction)->RangeMultiplier(2)->Range(1 << 10, 1 << 20);
//->Arg(1000)->Arg(1000000);
// Run the benchmark
BENCHMARK_MAIN();

/*
#include <chrono>
#include "../include/queue.h"
#include <iostream>

int main()
{
    
    auto queue_start = std::chrono::high_resolution_clock::now();
    int size = 100000000;
    queue::queue_stck_t<int> mystckqueue {};
    for (int iter = 0; iter < size; iter++) {
        mystckqueue.push(iter);
    }
    for (int iter = 0; iter < size; iter++) {
        int a = mystckqueue.pop();
    }
    auto queue_finish = std::chrono::high_resolution_clock::now();
    auto queue_elapsed = std::chrono::duration<double, std::milli>(queue_finish - queue_start);
    std::cout << queue_elapsed.count() << std::endl;

    queue_start = std::chrono::high_resolution_clock::now();

    queue::queue_t<int> mylstqueue {};
    for (int iter = 0; iter < size; iter++) {
        mylstqueue.push(iter);
    }
    for (int iter = 0; iter < size; iter++) {
        int a = mylstqueue.pop();
    }
    queue_finish = std::chrono::high_resolution_clock::now();
    queue_elapsed = std::chrono::duration<double, std::milli>(queue_finish - queue_start);
    std::cout << queue_elapsed.count() << std::endl;
    
    
    auto queue_start = std::chrono::high_resolution_clock::now();
    int size = 1000;
    queue::queue_stck_t<int> mystckqueue {};
    for (int iter = 0; iter < size; iter++) {
        mystckqueue.push(iter);
    }
    for (int iter = 0; iter < 100; iter++) {
        for (int iter = 0; iter < 20; iter++) {
            mystckqueue.pop();
        }
        for (int iter = 0; iter < 20; iter++) {
            mystckqueue.push(iter);
        }
    }
    auto queue_finish = std::chrono::high_resolution_clock::now();
    auto queue_elapsed = std::chrono::duration<double, std::milli>(queue_finish - queue_start);
    std::cout << queue_elapsed.count() << std::endl;

    queue_start = std::chrono::high_resolution_clock::now();

    queue::queue_t<int> mylstqueue {};
    for (int iter = 0; iter < size; iter++) {
        mylstqueue.push(iter);
    }
    for (int iter = 0; iter < 100; iter++) {
        for (int iter = 0; iter < 20; iter++) {
            mylstqueue.pop();
        }
        for (int iter = 0; iter < 20; iter++) {
            mylstqueue.push(iter);
        }
    }
    queue_finish = std::chrono::high_resolution_clock::now();
    queue_elapsed = std::chrono::duration<double, std::milli>(queue_finish - queue_start);
    std::cout << queue_elapsed.count() << std::endl;
    
    auto queue_start = std::chrono::high_resolution_clock::now();
    int size = 1000000;
    queue::queue_stck_t<int> mystckqueue {};
    for (int iter = 0; iter < size; iter++) {
        mystckqueue.push(iter);
    }
    for (int iter = 0; iter < size; iter++) {
        mystckqueue.pop();
    }
    auto queue_finish = std::chrono::high_resolution_clock::now();
    auto queue_elapsed = std::chrono::duration<double, std::milli>(queue_finish - queue_start);
    std::cout << queue_elapsed.count() << std::endl;

    queue_start = std::chrono::high_resolution_clock::now();

    queue::queue_t<int> mylstqueue {};
    for (int iter = 0; iter < size; iter++) {
        mylstqueue.push(iter);
    }
    for (int iter = 0; iter < size; iter++) {
        mylstqueue.pop();
    }
    queue_finish = std::chrono::high_resolution_clock::now();
    queue_elapsed = std::chrono::duration<double, std::milli>(queue_finish - queue_start);
    std::cout << queue_elapsed.count() << std::endl;

    return 0;
}
*/