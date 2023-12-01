cmake_minimum_required(VERSION 3.26)
project(OOP_Lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_Lab
        Cell.cpp
        Cell.h
        Character.cpp
        Character.h
        Field.cpp
        Field.h
        main.cpp
        Manager.cpp
        Manager.h)
