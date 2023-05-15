#include <iostream>

class Nodo{
    int dato;
    int indice;
    Nodo *anterior;
    friend class Pila;

    public:

    Nodo(int _dato);


};
