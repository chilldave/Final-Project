#include "pila.h"

Pila::Pila(){
    tope =NULL;
    tamano = 0;
}
Pila::~Pila() {
    while(tope != NULL) {
        Nodo* tmp = tope;
        tope = tope->anterior;
        delete tmp;
    }
}
bool Pila::empty(){
    return tope==NULL;
}

void Pila::currentTope(){
    std::cout<<"El tope actual es: "<<tope->dato<<" en direccion -> "<<tope<<std::endl;
}

void Pila::push(int dato){
    Nodo* nuevo = new Nodo(dato);
    nuevo->anterior = tope;
    nuevo->indice = tamano;
    tope = nuevo;
    std::cout << "\n- " << dato << " fue ingresado en la direccion de memoria -> " << nuevo << std::endl;
    tamano++; total_bytes += sizeof(dato);
}

void Pila::pop(){
    Nodo* aux = tope;
    std::cout << "- " << aux->dato << " con direccion -> {" << aux << "} : Tope eliminado" << std::endl;
    tope = tope->anterior;
    tamano--; total_bytes -= sizeof(aux->dato);
    delete aux;
}

void Pila::printff(){
    Nodo* aux = tope;
    std::cout << "La pila tiene un tamaño total de -> " << tamano << std::endl;
    std::cout << "Tiene un peso total de -> " << total_bytes << "B" << std::endl;
    while(aux!= NULL)
    {
        std::cout << "\n[" << aux->indice << "] - " << aux->dato << " en direccion de memoria -> "<< aux;
        aux = aux -> anterior;
    }
}

void Pila::clean(){
    Nodo* aux = tope;
    while(tope!= NULL){
        aux = tope;
        // std::cout<<aux->dato<<std::endl;
        tope = tope-> anterior;
        delete(aux);
    }
}

