# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++1z")

project(Exercism CXX)
add_subdirectory(source)
add_subdirectory(tests)
enable_testing()

#add_test(Test ${CMAKE_CURRENT_DIR}/tests/"*.cpp" COMMAND Test)
#add_test(NAME MyTest COMMAND Test)
