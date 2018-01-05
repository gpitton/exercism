#cmake_minimum_required(VERSION 2.8.11)

#file(GLOB Exercism_SRC "*.h" "*.cpp")
#add_library(Exercism_lib SHARED ${Exercism_SRC})

file( GLOB LIB_SOURCES *.cpp )
file( GLOB LIB_HEADERS *.h )
add_library( Exercism_lib ${LIB_SOURCES} ${LIB_HEADERS} )
