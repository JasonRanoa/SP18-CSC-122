cmake_minimum_required(VERSION 3.8)
project(Project_Files)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Length1.cpp Length1.h)
add_executable(Project_Files ${SOURCE_FILES})