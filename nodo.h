#include <iostream>

class Nodo{
	std::string dato;
    int indice;
    Nodo *anterior;
    friend class Pila;

    public:

    Nodo(std::string);


};
