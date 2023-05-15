#include "nodo.h"

class Pila{

    Nodo* tope;
    int tamano;
    size_t total_bytes;

    public:
    Pila();
    ~Pila();
    bool empty();
    void currentTope();
    void push(int);
    void pop();
    void printff();
    void clean();
};
