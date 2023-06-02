#include "pila_cola.h"
#include "colors.h"
#include <string.h>

// PARTE DE LA PILA 
Pila::Pila(){
    tope =NULL;
    tamano = 0;
}
Pila::~Pila() {
    while(tope != NULL) {
        Nodo* tmp = tope;
        tope = tope->siguiente;
        delete tmp;
    }
}

//Verificar si la pila esta vacia 
bool Pila::empty(){
    return tope==NULL;
}

//Mostrar el tope actual
void Pila::currentTope(){
    std::cout<<"\n\t\tEl tope actual es: "<<FG_Yellow<<tope->dato<<FG_White<<" en direccion -> "<<FG_Green<<tope<<FG_White<<std::endl;
}

//Agregar valores a la pila 
void Pila::push(std::string dato){
    Nodo* nuevo = new Nodo(dato);
    nuevo->siguiente = tope;
    nuevo->indice = tamano;
    tope = nuevo;
    tamano++;
    std::cout << "\n\t\t- " << dato << " fue ingresado en la direccion de memoria -> " <<FG_Green<<nuevo<<FG_White<< std::endl;
}

//Elimina los datos y los muestra;
void Pila::pop2(){

    Nodo* aux = tope;
    std::cout << FG_Green << "\n\t\t- " << aux->dato << " con direccion -> {" <<FG_Yellow << aux << FG_Green << "} - Tope eliminado" << FG_White << std::endl;
    tope = tope->siguiente;
     tamano--;
     delete aux;
}

std::string Pila::pop(){

    Nodo* aux  = tope;
    std::string element = aux->dato;
    tope = tope->siguiente;
    delete aux;
    return element;
}

void Pila::print(){
    Nodo* aux = tope;
    std::cout << "\n\t\tLa pila tiene un tamaño total de -> " << FG_Green << tamano << FG_White << std::endl;
    while(aux!= NULL)
    {
        std::cout << "\n\t\t[" << aux->indice << "] - " << FG_Red << aux->dato << FG_White << " en direccion de memoria -> "<< FG_Yellow << aux << FG_White;
        aux = aux -> siguiente;
    }
}
void Pila::clean(){
    Nodo* aux = tope;
    while(tope!= NULL){
        aux = tope;
        // std::cout<<aux->dato<<std::endl;
        tope = tope-> siguiente;
        delete(aux);
    }
	tamano = 0;
}



//Cola

Cola::Cola(){
    begin = NULL;
    end = nullptr;

}

bool Cola::cEmpty(){

    return begin == nullptr;
}

void Cola::cPush(std::string elemento){

    Nodo* nuevaCola = new Nodo(elemento);

    // nuevoCola->dato = elemento;
    // nuevoCola->siguiente = nullptr;
    if(cEmpty()){
        begin = nuevaCola;
        // begin->siguiente = NULL;
        end = nuevaCola;
        // end = nuevoCola;
    }else{

        end->siguiente=nuevaCola;
        // nuevaCola->siguiente= NULL;
        end = nuevaCola;
    }

}

std::string Cola::cPop(){
    if(cEmpty()){
        std::cout<<"Esta vacia\n\n";
    }
    Nodo* aux = begin;
    std::string element = aux->dato;
    begin = begin->siguiente;
    delete aux;

    if(begin == nullptr)
        end = nullptr;

    return  element;
}


void Cola::cPrint(){

    Nodo* current = begin;
    if(begin!= NULL){
        while(current!=NULL){
        
            std::cout<<"\n\t\t\t"<<current->dato;
            current = current->siguiente;
        }
    }else{

         std::cout<<"\n\t\tLa cola esta vacia\n";
    }
} 

void Cola::reverse(){
    if(cEmpty()){
        std::cout<<"\n\t\t\tLa cola esta vacia";
    }
    Nodo* actual  = begin;
    Nodo* anterior = nullptr;
    Nodo* siguiente = nullptr;

    while(actual != nullptr){
        siguiente = actual->siguiente;
        actual->siguiente= anterior;
        anterior = actual;
        actual = siguiente;
    }
    end = begin;
    begin = anterior; 
}

void CopyUntilSpecData(Pila& pila, Cola& cola, std::string valor){
    while(!pila.empty()){

        std::string element  = pila.pop();
        if(element == valor)
        {
            pila.push(element);
            break;
        }
        cola.cPush(element);
    }
}

void returnQueueToStack(Pila & pila, Cola& cola){
    while (!cola.cEmpty())
    {
        std::string element = cola.cPop();
        pila.push(element);
    }
}

