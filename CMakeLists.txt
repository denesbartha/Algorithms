cmake_minimum_required(VERSION 3.8)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES class03.cpp main.cpp class04.cpp lset.h lstack.h class05.cpp class06.cpp)
add_executable(Algorithms ${SOURCE_FILES})