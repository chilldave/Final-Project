#include "nodo.h"

class Pila{

    Nodo* tope;
    int tamano;

    public:
    Pila();
    ~Pila();
    bool empty();
    int  currentTope();
    void push(int dato);
    void pop();
    void printff();
    int clean();
    


};
