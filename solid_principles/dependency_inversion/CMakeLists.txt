cmake_minimum_required(VERSION 3.8)
project(dependency_inversion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(dependency_inversion ${SOURCE_FILES})