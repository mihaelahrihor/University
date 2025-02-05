cmake_minimum_required(VERSION 3.27)
project(Practic)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Practic
        Member.cpp
        Member.h
        MemberRegistery.cpp
        MemberRegistery.h
        Controller/GymController.cpp
        UI/GymView.cpp
        App/GymApp.h
        App/GymApp.cpp
        Repository/MemberRegistery.h
        Repository/MemberRegistery.cpp
        mainteste.cpp)
