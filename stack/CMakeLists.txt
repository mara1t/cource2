cmake_minimum_required(VERSION 3.16)

project(stack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES src/stack.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})

target_include_directories (${PROJECT_NAME} PRIVATE include)

add_compile_options (-Werror -Wall -Wextra -Wpedantic)

#tests

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (TEST_SOURCES test/stack_unit_tests.cpp)

add_executable(stack_unit_test ${TEST_SOURCES})

target_include_directories (stack_unit_test PRIVATE include)
target_link_libraries(stack_unit_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)