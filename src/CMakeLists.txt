cmake_minimum_required(VERSION 2.6)

project(SMI)

set(SMI_VERSION_MAJOR 0)
set(SMI_VERSION_MINOR 1)
set(SMI_VERSION_PATCH 0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(smi main.cpp Token.cpp Interpreter.cpp)
