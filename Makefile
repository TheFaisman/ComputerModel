all: main.exe

main.exe: main.o
	g++ -o main.exe main.o

main.o: main.cpp 
	g++ -c -std=c++17 main.cpp transistor_api.hpp

clean:
	del main.exe main.o