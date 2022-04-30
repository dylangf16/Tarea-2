cmake_minimum_required(VERSION 3.22)
project(Tarea_2)

include_directories(/usr/local/lib/pkgconfig)
find_library(Tarea_2_lib Tarea_2)

set(frameworks $(Tarea_2_lib))

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp Server.cpp Server.h)

add_executable(Tarea_2 ${SOURCE_FILES})
target_link_libraries(Tarea_2 gtest gtest_main)