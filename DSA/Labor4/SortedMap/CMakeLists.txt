cmake_minimum_required(VERSION 3.27)
project(SortedMap__1_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SortedMap__1_
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMIterator.cpp
        SMIterator.h
        SortedMap.cpp
        SortedMap.h)
