cmake_minimum_required(VERSION 3.27)
project(Controller_Autos C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Controller_Autos
        control.h
        control.cpp)
