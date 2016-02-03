cmake_minimum_required(VERSION 2.6)
project(SMI)

list(APPEND CMAKE_CXX_FLAGS "-std=c++1y -g")

set(SMI_SOURCES
	Interpreter.hpp
	Interpreter.cpp)

set(SMI_LIBRARIES
	readline)

add_executable(smi ${SMI_SOURCES})
target_link_libraries(smi ${SMI_LIBRARIES})
install(TARGETS smi DESTINATION bin)
