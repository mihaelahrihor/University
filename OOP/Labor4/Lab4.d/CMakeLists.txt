cmake_minimum_required(VERSION 3.27)
project(Lab4_d)

set(CMAKE_CXX_STANDARD 14)

include_directories(controller)
include_directories(domain)
include_directories(repository)
include_directories(ui)

add_executable(Lab4_d
        controller/Controller.cpp
        controller/Controller.h
        domain/Product.cpp
        domain/Product.h
        repository/Repository.cpp
        repository/Repository.h
        ui/Ui.cpp
        ui/Ui.h
        main.cpp)
