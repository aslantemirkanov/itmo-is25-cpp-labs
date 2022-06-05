cmake_minimum_required(VERSION 3.20)
project(MyAllocator)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyAllocator main.cpp Allocator.h MyPool.h)
