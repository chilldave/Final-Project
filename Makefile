PROGRAM_NAME=dinamic_memory
CXX=g++
OBJS=main.o pila.o nodo.o

all: $(OBJS)
	$(CXX) -o $(PROGRAM_NAME) $(OBJS)
	@rm -rf *.o

main.o: main.cpp
	$(CXX) main.cpp -o main.o

pila.o: pila.cpp
	$(CXX) pila.cpp -o pila.o

nodo.o: nodo.cpp
	$(CXX) nodo.cpp -o nodo.o
