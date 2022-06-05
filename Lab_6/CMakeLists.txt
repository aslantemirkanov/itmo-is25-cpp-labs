cmake_minimum_required(VERSION 3.20.2)
project(meta_programming)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ")
set(SOURCE_FILES main.cpp polynomial.h)

add_executable(meta_programming ${SOURCE_FILES} polynomial.h)


# 'lib' is the folder with Google Test sources
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(meta_programming gtest pthread)
target_link_libraries(meta_programming gtest gtest_main)
