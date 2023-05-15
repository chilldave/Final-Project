#include <iostream>
#include <unistd.h>
#include "pila.h"
using namespace std;

int main(){

    Pila* pila = new Pila();
    int opc = 0;
    // system("clear");
    while(opc != 6)
    {
        system("clear");
        system("figlet -c -t -k Byte Band: Pila");
        cout<<"\n\n\t\t\tDireccion de nuestra pila -> "<<pila<<endl<<endl;
        cout<<"\t\t\t1. Insertar\n";
        cout<<"\t\t\t2. Eliminar\n";
        cout<<"\t\t\t3. Mostrar\n";
        cout<<"\t\t\t4. Mostrar tope\n";
        cout<<"\t\t\t5. Vaciar\n";
        cout<<"\t\t\t6. Salir\n";
        cout<<endl;
        cout<<"\t\t\tElija una opcion(1-6): ";
        cin>>opc;

        system("clear");
        switch(opc){
            case 1: {
                int dato;
                cout<<"Ingrese un dato : ";
                cin>>dato;
                pila->push(dato);
                break;
            }
            case 2: {
                if(pila->empty())
                {
                    cout<<"La pila esta vacia\n";
                }else{
                    pila->pop();
                }
                break;
            }
            case 3: {
                if(pila->empty())
                {
                    cout<<"La pila esta vacia\n";
                }else{
                    cout<<"Todos los elementos de la pila: \n";
                    pila->printff();
                }
                break;
            }
            case 4:{
                if(pila->empty()){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                    pila->currentTope();
                }
                break;
            }
            case 5: {
                if(pila->empty()){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                    pila->clean();
                    cout<<"Todos los elementos de la pila fuero eliminados exitosamente\n";
                }
                break;
            default:
                cout<<"\nThanks for using it!\n\n";
                continue;
                
            }
        }  
        cout<<"\nPress ENTER to continue ... ";
        cin.get();
        cin.get();
    }
    return 0;
}
