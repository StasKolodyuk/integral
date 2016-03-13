cmake_minimum_required(VERSION 3.3)
project(integral)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.cpp)
add_executable(integral ${SOURCE_FILES})