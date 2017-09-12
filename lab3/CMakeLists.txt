cmake_minimum_required(VERSION 3.8)
project(lab3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp list_functions.h QueueWithPriority.h)
add_executable(lab3 ${SOURCE_FILES})