#include "pila.h"

Pila::Pila(){
    tope =NULL;
    tamano = 0;

}
bool Pila::empty(){

    return tope==NULL;

}

int Pila::currentTope(){

    if(empty())
    {
        return -1;
    }
    return tope->dato;
}

void Pila::push(int dato){
    Nodo* nuevo = new Nodo(dato);
    if(empty())
    {
        tope = nuevo;
    }else{
        nuevo -> anterior = tope;
        tope = nuevo;
    }
    tamano++;
}

void Pila::pop(){

    if(!empty()){
        Nodo* aux = tope;
        tope= tope->anterior;
        delete aux;
    }
}

void Pila::printff(){
    Nodo* aux = tope;

    while(aux!= NULL)
    {
        std::cout<<aux->dato<<std::endl;
        aux = aux -> anterior;
    }
}

int Pila::clean(){

    Nodo* aux = tope;
    while(tope!= NULL){
        aux = tope;
        // std::cout<<aux->dato<<std::endl;
        tope = tope-> anterior;
        delete(aux);

    }
    int tmp = tamano;
    tamano = 0;
    return tmp;
}

