CXX = g++
CXXFLAGS= -Wall -Wextra -std=c++11 -pedantic

.PHONY: all

all: Database.o Employee.o main.o test_lib.so main clean


#-L. де шукати бібліотеку input.a. '.' значить в поточному каталозі

main: main.o test_lib.so
	g++ -o main main.o -L. -l:test_lib.so -Wl,--rpath -Wl,. 

Database.o: Database.cpp
	g++ -c -fPIC Database.cpp

Employee.o: Employee.cpp
	g++ -c -fPIC Employee.cpp

main.o:
	gcc -c main.cpp

test_lib.so: Database.o Employee.o
	g++ -shared -o test_lib.so Database.o Employee.o

clean:
	rm -f *.o
