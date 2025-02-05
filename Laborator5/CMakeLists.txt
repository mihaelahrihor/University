cmake_minimum_required(VERSION 3.27)
project(Laborator5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laborator5
        Graph.cpp
        Graph.h
        Graph_teste.cpp)
