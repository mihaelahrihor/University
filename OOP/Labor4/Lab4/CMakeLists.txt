cmake_minimum_required(VERSION 3.27)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4
        Controller.cpp
        Controller.h
        main.cpp
        Product.cpp
        Product.h
        Repo.cpp
        Repo.h
        Ui.cpp
        Ui.h)
