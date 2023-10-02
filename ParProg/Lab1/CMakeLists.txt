cmake_minimum_required(VERSION 3.26)
project(Lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab1 main.c
        data.c
        func1.c
        func2.c
        func3.c
        data.h
        func1.h
        func2.h
        func3.h)
