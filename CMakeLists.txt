# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++1z")
set(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")

project(Exercism CXX)
add_subdirectory(source)
add_subdirectory(tests)
enable_testing()

#add_test(Test ${CMAKE_CURRENT_DIR}/tests/"*.cpp" COMMAND Test)
#add_test(NAME MyTest COMMAND Test)
