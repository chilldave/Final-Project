#include <iostream>
#include "pila.h"
using namespace std;

int main(){

    Pila* pila = new Pila();
    int opc = 0;

    while(opc != 6)
    {
        system("clear");
        cout<<"1. Insertar\n";
        cout<<"2. Eliminar\n";
        cout<<"3. Mostrar\n";
        cout<<"4. Mostrar tope\n";
        cout<<"5. Vaciar\n";
        cout<<"6. Salir\n";
        cout<<endl;
        cout<<"Elija una opcion";
        cin>>opc;

        system("clear");
        switch(opc){
            case 1: {
                int dato;
                cout<<"Ingrese un dato";
                cin>>dato;
                pila->push(dato);
                break;
            }
            case 2: {
                pila->pop();
                cout<<"El ultimo tope fue eliminado"<<endl;
                break;
            }
            case 3: {
                if(pila->empty())
                {
                    cout<<"La pila esta vacia\n";
                }else{
                cout<<"\nPila: \n";
                pila->printff();
                }
                break;
            }
            case 4:{
                if(pila->empty()){
                    cout<<"La pila esta vacia"<<endl;
                }else{

                
                int numero = pila->currentTope();
                cout<<"El tope actual es : "<<numero<<endl;
                break;
                }
            }
            case 5: {
                if(pila->empty()){
                    cout<<"La pila esta vacia"<<endl;
                }else{

            
                pila->clean();
                cout<<"Todos los elementos de la pila fuero eliminados exitosamente\n";
                break;
                }
            default:
                cout<<"Valor no encontrado\n";
                continue;
                
                // break;
            }
            // case 6: break;
        }  
    
        
    }
    return 0;

}
