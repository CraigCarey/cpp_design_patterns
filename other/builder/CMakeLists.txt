cmake_minimum_required(VERSION 3.8)
project(builder)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.cpp Person.h PersonBuilder.cpp PersonBuilder.h PersonJobBuilder.h PersonAddressBuilder.h)
add_executable(builder ${SOURCE_FILES})