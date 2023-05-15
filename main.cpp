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
        system("figlet -c Byte Band Pila");
        cout<<"\t\t\t\t1. Insertar\n";
        cout<<"\t\t\t\t2. Eliminar\n";
        cout<<"\t\t\t\t3. Mostrar\n";
        cout<<"\t\t\t\t4. Mostrar tope\n";
        cout<<"\t\t\t\t5. Vaciar\n";
        cout<<"\t\t\t\t6. Salir\n";
        cout<<endl;
        cout<<"Elija una opcion : ";
        cin>>opc;

        system("clear");
        switch(opc){
            case 1: {
                // system("clear");
                int dato;
                cout<<"Ingrese un dato : ";
                cin>>dato;
                pila->push(dato);
                cout<<"\nDato ingresado correctamente. "<<endl;
                // sleep(2);
                // system("clear");
                break;
            }
            case 2: {
                // system("clear");
                pila->pop();
                cout<<"El ultimo tope fue eliminado\n"<<endl;
                // sleep(3);
                // system("clear");
                
                break;
            }
            case 3: {
                // system("clear");
                if(pila->empty())
                {
                    cout<<"La pila esta vacia\n";
                    // sleep(3);
                }else{
                cout<<"Todos los elementos de la pila : \n";
                pila->printff();
                }
                // sleep(3);
                // system("clear");
                break;
            }
            case 4:{
                // system("clear");
                if(pila->empty()){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                int numero = pila->currentTope();
                cout<<"El tope actual es : "<<numero<<endl;
                break;
                }
            }
            case 5: {
                // system("clear");
                if(pila->empty()){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                pila->clean();
                cout<<"Todos los elementos de la pila fuero eliminados exitosamente\n";
                break;
                }
            default:
                cout<<"\nThanks for using it!\n\n";
                continue;
                
                // break;
            }
            // case 6: break;
        }  
        cout<<"\nPress ENTER to continue ... ";
        cin.get();
        cin.get();
    
        
    }
    return 0;

}
