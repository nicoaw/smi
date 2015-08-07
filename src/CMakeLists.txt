cmake_minimum_required(VERSION 2.6)

project(SMI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(SMI_SOURCES
	Debug.cpp
	Debug.hpp
	Evaluate.cpp
	Evaluate.hpp
	Form.cpp
	Form.hpp
	main.cpp
	Real.hpp
	Token.cpp
	Token.hpp)

add_executable(smi ${SMI_SOURCES})
