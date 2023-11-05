CXX = g++
CXXFLAGS= -Wall -Wextra -std=c++11 -pedantic

.PHONY: all

all: main run

main: main.cpp Database.cpp Employee.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp Database.cpp Employee.cpp

run: main
	./main
