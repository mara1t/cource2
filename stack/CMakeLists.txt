cmake_minimum_required(VERSION 3.16)

project(stack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (TEST_SOURCES test/stack_unit_tests.cpp)

add_executable (${PROJECT_NAME} ${TEST_SOURCES})

target_include_directories (${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

add_compile_options (-O2 -Werror -Wall -Wextra -Wpedantic)

# To add:
# cmake .. -DCLANG_TIDY_FLAG=true
# cmake --build .

if(CLANG_TIDY_FLAG)
    set(CMAKE_CXX_CLANG_TIDY 
        clang-tidy;
        -checks=google-*,cppcoreguidelines-*
    )
    set_target_properties(${PROJECT_NAME} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_FLAGS}")
    
endif()

if(CLANG_FORMAT_FLAG)
    file(GLOB_RECURSE ALL_SOURCE_FILES include/*.h test/*.cpp)
    add_custom_target(
        clang_format
        COMMAND clang-format
        -i
        ${ALL_SOURCE_FILES}
    )
endif()

if(SANITIZER_FLAG)
    target_compile_options(${PROJECT_NAME} PUBLIC -fsanitize=address -g)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()

