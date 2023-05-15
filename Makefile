PROGRAM_NAME=dinamic_memory
CXX=g++
CXXFLAGS=-g -ltinfo -pipe
OBJS=main.o pila.o nodo.o

all: $(OBJS)
	$(CXX) -o $(PROGRAM_NAME) $(OBJS) -ltinfo
	@rm -rf *.o

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

pila.o: pila.cpp
	$(CXX) -c $(CXXFLAGS) pila.cpp -o pila.o

nodo.o: nodo.cpp
	$(CXX) -c $(CXXFLAGS) nodo.cpp -o nodo.o
