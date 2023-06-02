#include "nodo.h"

class Cola{


    Nodo* begin;
    Nodo* end;
 

    public:
    Cola();

    bool cEmpty();
    void cPush(std::string);
    std::string cPop();
    void cPrint();
    void reverse();

};
class Pila {

    Nodo* tope;
    int tamano;

    public:

    Pila();
    ~Pila();
    bool empty();
    void currentTope();
    void push(std::string);
    std::string pop();
    void pop2();
    // void update(std::string);
    void print();
    //clear everything in the stack
    void clean();
};

void CopyUntilSpecData(Pila& pila, Cola& cola, std::string valor);

void returnQueueToStack(Pila & pila, Cola& cola);





