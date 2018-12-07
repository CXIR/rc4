cmake_minimum_required(VERSION 3.0)
project(my_project)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fdiagnostics-color=auto")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

add_executable(rc4 main.cpp src/RC4.h src/RC4.cpp src/FileManager.h src/FileManager.cpp src/FileIO.h src/FileIO.cpp)

#UNIT TESTS
enable_testing()
add_subdirectory(lib/gtest)

configure_file(${CMAKE_CURRENT_LIST_DIR}/data/hello.txt
               ${CMAKE_CURRENT_BINARY_DIR}/data/hello.txt COPYONLY)


add_subdirectory(test)


# Benchmark
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(lib/benchmark)

add_subdirectory(benchmark)
