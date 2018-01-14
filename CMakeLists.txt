# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++1z -g -O0 --coverage")
SET(COVERAGE ON CACHE BOOL "Coverage")

enable_testing()

project(Exercism CXX)
add_subdirectory(source)
add_subdirectory(tests)

