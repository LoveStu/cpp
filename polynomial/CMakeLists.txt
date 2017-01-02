cmake_minimum_required(VERSION 3.6)
project(new_pol)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp polynomial.h polynomial.cpp)
add_executable(new_pol ${SOURCE_FILES})