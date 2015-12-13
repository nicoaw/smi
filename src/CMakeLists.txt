cmake_minimum_required(VERSION 2.6)
project(SMI)

list(APPEND CMAKE_CXX_FLAGS "-std=c++1y -g")

set(SMI_SOURCES
	Interpreter.hpp
	Interpreter.cpp
	main.cpp
	Token.hpp)

add_executable(smi ${SMI_SOURCES})
install(TARGETS smi DESTINATION bin)
