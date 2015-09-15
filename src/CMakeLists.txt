cmake_minimum_required(VERSION 2.6)
project(SMI)

list(APPEND CMAKE_CXX_FLAGS "-std=c++1y -g")

set(SMI_SOURCES
	Expression.hpp
	Expression.cpp
	main.cpp
	Operator.hpp
	Token.hpp)

add_executable(smi ${SMI_SOURCES})
target_link_libraries(smi boost_program_options)
