cmake_minimum_required(VERSION 3.21)

project(Lab_2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lcurl -pthread -lglfw -lGLEW -lGL -lGLU")

add_executable(Lab_2 main.cpp curl_class.h json_classes.cpp json_classes.h )

target_link_libraries(Lab_2 curl)
target_link_libraries(Lab_2 -lglut -lglfw -lGLEW -lGL -lGLU)

