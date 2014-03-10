cmake_minimum_required (VERSION 2.8)
project (dotray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost 1.53.0 COMPONENTS unit_test_framework)

add_subdirectory (src)
add_subdirectory (tests)

