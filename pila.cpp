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

void Pila::push(std::string dato){
    Nodo* nuevo = new Nodo(dato);
    nuevo->anterior = tope;
    nuevo->indice = tamano;
    tope = nuevo;

    tamano++;

    std::cout << "\n- " << dato << " fue ingresado en la direccion de memoria -> " <<FG_Green<<nuevo<<FG_White<< std::endl;
}
void Pila::pop(){
    Nodo* aux = tope;
    std::cout << FG_Green << "- " << aux->dato << " con direccion -> {" <<FG_Yellow << aux << FG_Green << "} - Tope eliminado" << FG_White << std::endl;
    tope = tope->anterior;
    tamano--;
    delete aux;
}
void Pila::update(int index, std::string dato) {
	if (index < 0 or index > tamano) {
		std::cout << FG_Red << "El indice ingresado no es correcto, ingrese uno que este en el rango de la pila!" << FG_White << std::endl;
		return;
	}
	Nodo* aux = tope;
	while (aux != NULL) {
		if (aux->indice != index-1) {
			aux = aux->anterior;
			continue;
		};
		std::cout << FG_Green << "El indice " << index << " con valor " << aux->dato << " y direccion -> " << "{" << FG_Yellow << aux  << FG_Green << "}\nFue actualizado exitosamente con el valor -> " << FG_Yellow << dato << FG_White << std::endl;
		aux->dato = dato;
		break;
	}
}
void Pila::printff(){
    Nodo* aux = tope;
    std::cout << "La pila tiene un tamaño total de -> " << FG_Green << tamano << FG_White << std::endl;
    while(aux!= NULL)
    {
        std::cout << "\n[" << tamano-aux->indice << "] - " << FG_Red << aux->dato << FG_White << " en direccion de memoria -> "<< FG_Yellow << aux << FG_White;
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
	tamano = 0;
}
