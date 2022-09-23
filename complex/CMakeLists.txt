cmake_minimum_required(VERSION 3.16)

project(complex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES src/main.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})

add_compile_options (-Werror -Wall -Wextra -Wpedantic)