cmake_minimum_required(VERSION 3.28)
project(SET03 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 23)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

#### the list of targets ####
add_executable(A1 A1/main.cpp)
add_executable(A2 A2/main.cpp A2/sortTester.h A2/sort.h A2/arrayGenerator.h)
add_executable(A3 A3/main.cpp A3/arrayGenerator.h A3/sort.h A3/sortTester.h)
add_executable(P1 P1/main.cpp)
add_executable(P2 P2/main.cpp)
add_executable(P3 P3/main.cpp)
add_executable(P4 P4/main.cpp)
add_executable(P5 P5/main.cpp)
add_executable(P6 P6/main.cpp)

# target_link_libraries(P1 PRIVATE Catch2::Catch2WithMain)
