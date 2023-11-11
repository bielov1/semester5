cmake_minimum_required(VERSION 3.26)
project(Lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2 main.c
        Database.h
        task1.h
        task2.h
        task4.h
        task3.c
        Database.c
        task1.c
        task2.c
        task4.c)
