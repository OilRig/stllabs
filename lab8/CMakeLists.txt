cmake_minimum_required(VERSION 3.8)
project(lab8)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Shape.h Circle.h Triangle.h Square.h)
add_executable(lab8 ${SOURCE_FILES})