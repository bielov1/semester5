CXX = g++
CXXFLAGS= -Wall -Wextra -std=c++11 -pedantic

.PHONY: all

all: Database.o Employee.o main.o archive main clean


#-L. де шукати бібліотеку input.a. '.' значить в поточному каталозі

main: main.o input.a
	g++ main.o input.a -o main -L. -l:input.a

Database.o: Database.cpp
	g++ Database.cpp -c -o Database.o

Employee.o: Employee.cpp
	g++ Employee.cpp -c -o Employee.o 

main.o: main.cpp
	g++ main.cpp -c -o main.o

archive: Database.o Employee.o
	ar rcs input.a Database.o Employee.o

clean:
	rm -f *.o
