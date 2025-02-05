cmake_minimum_required(VERSION 3.27)
project(Lab4_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4_1
        controller.cpp
        controller.h
        main.cpp
        product.cpp
        product.h
        repository.cpp
        repository.h
        ui.cpp
        ui.h)
