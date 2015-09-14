cmake_minimum_required(VERSION 2.6)
project(SMI)

list(APPEND CMAKE_CXX_FLAGS "-std=c++1y")

set(SMI_SOURCES
	main.cpp
	Token.cpp
	Token.hpp)

add_executable(smi ${SMI_SOURCES})
