#!/bin/sh

set -xe


x86_64-w64-mingw32-gcc -o main main.c task1.c task2.c task3.c task4.c -L.
wine ./main.exe
