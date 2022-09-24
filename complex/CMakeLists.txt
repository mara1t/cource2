cmake_minimum_required(VERSION 3.16)

project(complex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES test/complex_test.cpp src/complex.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})

add_compile_options (-Werror -Wall -Wextra -Wpedantic)

#enable_testing()
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIR})

# Add test cpp 
#set(TEST_SOURCES test/testgtest.cpp src/main.cpp)

#add_executable(UnitTests ${TEST_SOURCES})

# Link test executable against gtest & gtest_main
#target_link_libraries(runUnitTests ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG})
