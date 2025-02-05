cmake_minimum_required(VERSION 3.27)
project(Laborator3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laborator3
        Graph.cpp
        Graph.h
        main.cpp)
