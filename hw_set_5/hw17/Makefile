CPPFLAGS=-std=c++11

run_test: all
	./test_program.sh

all: main test
	rm *.o

test: Coordinates.o test.o MonteCarlo.o Landscape.o run.o Uniform.o
	clang++ -o test Coordinates.o test.o Landscape.o MonteCarlo.o run.o Uniform.o

main: Coordinates.o main.o MonteCarlo.o Landscape.o run.o Uniform.o
	clang++ -o main Coordinates.o main.o Landscape.o MonteCarlo.o run.o Uniform.o

test.o: test.cc Coordinates.hh MonteCarlo.hh
	clang++ $(CPPFLAGS) -c test.cc

main.o: main.cc Coordinates.hh MonteCarlo.hh
	clang++ $(CPPFLAGS) -c main.cc

Coordinates.o: Coordinates.cc Coordinates.hh Landscape.hh
	clang++ $(CPPFLAGS) -c Coordinates.cc

MonteCarlo.o: Coordinates.hh MonteCarlo.hh MonteCarlo.cc Uniform.hh
	clang++ $(CPPFLAGS) -c MonteCarlo.cc

Uniform.o: Uniform.hh Uniform.cc
	clang++ $(CPPFLAGS) -c Uniform.cc

Landscape.o: Landscape.hh Landscape.cc
	clang++ $(CPPFLAGS) -c Landscape.cc