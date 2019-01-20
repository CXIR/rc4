cmake_minimum_required(VERSION 3.12)
project(rc4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(rc4 main.cpp src/RC4.h src/RC4.cpp src/FileIO.h src/FileIO.cpp)

#UNIT TESTS
enable_testing()
add_subdirectory(lib/gtest)

configure_file(${CMAKE_CURRENT_LIST_DIR}/src/file.txt
               ${CMAKE_CURRENT_BINARY_DIR}/test/file_test.txt COPYONLY)


add_subdirectory(test)


# Benchmark
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(lib/benchmark)

add_subdirectory(benchmark)