#include "nodo.h"

class Pila{

    Nodo* tope;
    int tamano;

    public:
    Pila();
    ~Pila();
    bool empty();
    void currentTope();
    void push(std::string);
    void pop();
    void update(int, std::string);
    void printff();
    void clean();
};
