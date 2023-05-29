#include "nodo.h"

class Pila{

    Nodo* tope;
    int tamano;
    friend class Cola;
    public:

    Pila();
    ~Pila();
    bool empty();
    void currentTope();
    void push(std::string);
    void pop();
    void update(std::string);
    void printff();
    void clean();
    // void search(std::string);
};

class Cola{
    Nodo* begin;
    Nodo* end;
    friend class Pila;
    public:
    Cola();
    bool emptyCola();
    void cPush(std::string);
    void cPop();
    void CopyStacktoQueue(Pila& pila, Cola& Cola);

};

