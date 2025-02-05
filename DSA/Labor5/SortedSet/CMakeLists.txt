cmake_minimum_required(VERSION 3.27)
project(SortedSet)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortedSet App.cpp ExtendedTest.h ExtendedTest.cpp ShortTest.h ShortTest.cpp
SortedSet.cpp SortedSet.h SortedSetIterator.cpp SortedSetIterator.h
        Stack.cpp
        Stack.h
        main.cpp)
