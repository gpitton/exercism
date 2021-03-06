# Locate Boost libraries: unit_test_framework, date_time and regex
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.59 REQUIRED COMPONENTS unit_test_framework date_time regex)

add_definitions(-DEXERCISM_RUN_ALL_TESTS)

macro( add_boost_testprogram  filename )
   add_executable(        ${filename}  ${filename}.cpp )
   if (COVERAGE)
       target_compile_options( ${filename} PRIVATE --coverage)
       target_link_libraries( ${filename} PRIVATE --coverage ${Boost_LIBRARIES} Exercism_lib gcov )
    else()
       target_link_libraries( ${filename}  ${Boost_LIBRARIES} Exercism_lib )
       add_custom_command(TARGET ${filename} POST_BUILD COMMAND ${filename})
    endif()
   #add_test(         NAME ${filename}  COMMAND ${filename} )
   add_test( ${filename} ${CMAKE_CURRENT_BINARY_DIR}/${filename} )
endmacro( add_boost_testprogram )

include_directories("${CMAKE_SOURCE_DIR}/source" ${Boost_INCLUDE_DIRS})

file(GLOB APP_SOURCES *.cpp)
foreach(testsourcefile ${APP_SOURCES})
    GET_FILENAME_COMPONENT(filename ${testsourcefile} NAME_WE)
    add_boost_testprogram(${filename})
endforeach(testsourcefile ${APP_SOURCES})

