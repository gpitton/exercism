# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++1z -g -O0 --coverage")
SET(COVERAGE ON CACHE BOOL "Coverage")
#SET(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} --coverage -fprofile-arcs -ftest-coverage")
#SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage -fprofile-arcs -ftest-coverage")
#SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} --coverage")

enable_testing()

project(Exercism CXX)
add_subdirectory(source)
add_subdirectory(tests)


#add_test(Test ${CMAKE_CURRENT_DIR}/tests/"*.cpp" COMMAND Test)
#add_test(NAME MyTest COMMAND Test)
