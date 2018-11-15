cmake_minimum_required(VERSION 3.12)
project(rc4)

set(CMAKE_CXX_STANDARD 11)

add_executable(rc4 main.cpp src/cipher.h src/decipher.h)