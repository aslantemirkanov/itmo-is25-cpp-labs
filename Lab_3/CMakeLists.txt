cmake_minimum_required(VERSION 3.20.2)
project(circular_buffer)

set(CMAKE_CXX_STANDARD 20)

add_executable(circular_buffer main.cpp Circular_buffer.h algorithms.h)
