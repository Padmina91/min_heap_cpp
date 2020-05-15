cmake_minimum_required(VERSION 3.15)
project(min_heap_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(min_heap_cpp main.cpp datenstruktur.cpp datenstruktur.hpp testtreiber.cpp testtreiber.hpp exception.cpp exception.hpp)