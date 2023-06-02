#include <iostream>

class Nodo{

	std::string dato;
    int indice;
    Nodo* siguiente;
    friend class Pila;
    friend class Cola;
    public:

    Nodo(std::string);
    // Nodo1(std::string);
};
