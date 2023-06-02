#include "nodo.h"



class Cola{


    Nodo* begin;
    Nodo* end;
    // friend class Pila;

    public:
    Cola();

    bool emptyCola();

    void cPush(std::string);

    void cPop();
    void cPrint();

    // void CopyStacktoQueue(Pila& pila, Cola& Cola);

};
class Pila : public Cola {

    Nodo* tope;
    int tamano;
    // friend class Cola;
    public:

    Pila();
    ~Pila();
    bool empty();
    void currentTope();
    void push(std::string);
    void pop();
    void update(std::string);
    void print();
    //clear everything in the stack
    void clean();
};



