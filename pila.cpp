#include "pila.h"
#include "colors.h"

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
    std::cout<<"El tope actual es: "<<FG_Yellow<<tope->dato<<FG_White<<" en direccion -> "<<FG_Green<<tope<<FG_White<<std::endl;
}

void Pila::push(int dato){
    Nodo* nuevo = new Nodo(dato);
    nuevo->anterior = tope;
    nuevo->indice = tamano;
    tope = nuevo;
    std::cout << "\n- " << dato << " fue ingresado en la direccion de memoria -> " <<FG_Green<<nuevo<<FG_White<< std::endl;
    tamano++; total_bytes += sizeof(dato);
}

void Pila::pop(){
    Nodo* aux = tope;
    std::cout << FG_Green << "- " << aux->dato << " con direccion -> {" <<FG_Yellow << aux << FG_Green << "} - Tope eliminado" << std::endl;
    tope = tope->anterior;
    tamano--; total_bytes -= sizeof(aux->dato);
    delete aux;
}

void Pila::printff(){
    Nodo* aux = tope;
    std::cout << "La pila tiene un tamaño total de -> " << FG_Green << tamano << FG_White << std::endl;
    std::cout << "Tiene un peso total de -> " << FG_Yellow << total_bytes << "B" << FG_White << std::endl;
    while(aux!= NULL)
    {
        std::cout << "\n[" << tamano-aux->indice << "] - " << aux->dato << " en direccion de memoria -> "<< FG_Yellow << aux << FG_White;
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

