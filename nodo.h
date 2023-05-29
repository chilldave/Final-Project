#include <iostream>

class Nodo{
	std::string dato;
    int indice;
    Nodo *anterior;
    friend class Pila;
    // friend class Cola;
    public:

    Nodo(std::string);
    // Nodo1(std::string);
};
