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
void Pila::pop(){

    Nodo* aux = tope;
    std::cout << FG_Green << "\n\t\t- " << aux->dato << " con direccion -> {" <<FG_Yellow << aux << FG_Green << "} - Tope eliminado" << FG_White << std::endl;
    tope = tope->siguiente;
    tamano--;
    delete aux;
}

void Pila::update(std::string nodoBuscar){
    Pila copy;
    Nodo* aux = tope;

    // std::cout << "\n\t\tLa pila tiene un tamaño total de -> " << FG_Green << tamano << FG_White << std::endl;
    std::string nodobuscado = nodoBuscar;
    int encontrado=0;
    if(tope !=NULL){

        while(aux!= NULL){
            if(nodobuscado == aux->dato){
                std::cout<<"\n\t\tNodo encontrado... \n";
                std::cout << "\n\t\t[" << tamano-aux->indice << "] - " << FG_Red << aux->dato << FG_White << " en direccion de memoria -> "<< FG_Yellow << aux << FG_White;
                std::cout << "\n\n\t\tIngrese el nuevo dato para actualizar " <<aux->dato<< ": ";
                std::cin.ignore();
				getline(std::cin,aux->dato,'\n');
                std::cout<<"\n\n Nodo Modificado exitosamente"<<std::endl; 
                encontrado = 1;
                break;
            }
            copy.cPush(aux->dato);
            pop();
            aux = aux -> siguiente;
        }
        if(encontrado ==0)
        {
            std::cout<<"\n\t\tNodo no encontrado "<<std::endl;
        }
    }
}


void Pila::print(){
    Nodo* aux = tope;
    std::cout << "\n\t\tLa pila tiene un tamaño total de -> " << FG_Green << tamano << FG_White << std::endl;
    while(aux!= NULL)
    {
        std::cout << "\n\t\t[" << tamano-aux->indice << "] - " << FG_Red << aux->dato << FG_White << " en direccion de memoria -> "<< FG_Yellow << aux << FG_White;
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

bool Cola::emptyCola(){

    return begin == nullptr;
}

void Cola::cPush(std::string elemento){

    Nodo* nuevaCola = new Nodo(elemento);

    // nuevoCola->dato = elemento;
    // nuevoCola->siguiente = nullptr;
    if(begin == NULL){
        begin = nuevaCola;
        begin->siguiente = NULL;
        end = begin;
        // end = nuevoCola;
    }else{

        end->siguiente=nuevaCola;
        nuevaCola->siguiente= NULL;
        end = nuevaCola;
    }

}


void Cola::cPrint(){

    Nodo* current = begin;
    if(begin!= NULL){
        while(current!=NULL){
            std::cout<<"\n "<<current->dato<<"\n";
            current = current->siguiente;
        }
    }else{

         std::cout<<"\n\t\tLa cola esta vacia\n";
    }


}


/* void cPrint()
{

    Nodo* actual = new Nodo();
    actual  = begin;
    while(actual != nullptr)
    {
        std::cout<<begin->dato<<" ";
        begin = begin->anterior;

    }
    std::cout;
}
    // void cPop();
 */
