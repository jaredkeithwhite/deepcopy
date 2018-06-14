cmake_minimum_required(VERSION 3.10)
project(deepcopy)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
set(SOURCE_FILES ${SOURCE_FILES} node.h)
set(SOURCE_FILES ${SOURCE_FILES} bigo/bigo.h bigo/bigo.cpp)
set(SOURCE_FILES ${SOURCE_FILES} memory/memory.h memory/memory.cpp)

add_executable(deepcopy ${SOURCE_FILES})