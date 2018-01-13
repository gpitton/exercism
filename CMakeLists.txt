# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++1z -g -O0 -coverage -fprofile-arcs -ftest-coverage")
#set(LDFLAGS    "-coverage -lgcov")
SET(CMAKE_EXE_LINKER_FLAGS="-fprofile-arcs -ftest-coverage")

enable_testing()

project(Exercism CXX)
add_subdirectory(source)
add_subdirectory(tests)

#add_test(Test ${CMAKE_CURRENT_DIR}/tests/"*.cpp" COMMAND Test)
#add_test(NAME MyTest COMMAND Test)
