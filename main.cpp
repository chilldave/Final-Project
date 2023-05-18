#include <iostream>
#include <unistd.h>
#include "pila.h"
#include "colors.h"

using namespace std;

int main(){

    Pila* pila = new Pila();
    bool loop = true;
    while(loop)
    {
        string opc;
        system("clear");
        system("figlet -c -t -k Byte Band: Pila");
        cout<<"\n\n\t\t\tDireccion de nuestra pila -> "<<FG_Red<<pila<<endl<<endl;
        cout<<FG_Yellow<<"\t\t\t1. Insertar\n";
        cout<<"\t\t\t2. Eliminar\n";
        cout<<"\t\t\t3. Actualizar\n";
        cout<<"\t\t\t4. Mostrar\n";
        cout<<"\t\t\t5. Mostrar tope\n";
        cout<<"\t\t\t6. Vaciar\n";
        cout<<"\t\t\t7. Salir\n";
        cout<<endl<<FG_White;
        cout<<"\t\t\tElija una opcion(1-7): ";
        cin>>opc;

        int _opcint = 0;
        try {
           _opcint = stoi(opc);
        } catch (const invalid_argument & e) {}

        system("clear");
        switch(_opcint){
            case 1: {
                string dato;
                cout<<"Ingrese el nuevo a almacenar en la pila: ";
				cin.ignore();
				getline(cin, dato);
                pila->push(dato);
                break;
            }
            case 2: {
                if(pila->empty())
                {
                    cout<<FG_Red<<"No se puede eliminar por que la pila esta vacia\n"<<FG_White;
                }else{
                    pila->pop();
                }
                break;
            }
			case 3: {
				if (pila->empty()) {
                    cout<<FG_Red<<"No se puede actualizar ninguna informacion por que la pila esta vacia\n"<<FG_White;
				} else {
					int index = 0;
					string dato;
					cout << "Ingrese el indice a actualizar: "; cin >> index;
					cout << "Ingrese el nuevo dato para el indice " << index << ": ";
					cin.ignore();
					getline(cin, dato);
					pila->update(index, dato);
				}
				break;
			}
            case 4: {
                if(pila->empty())
                {
                    cout<<FG_Red<<"No se puede mostrar ninguna informacion por que la pila esta vacia\n"<<FG_White;
                }else{
                    cout<<"Todos los elementos de la pila: \n";
                    pila->printff();
                }
                break;
            }
            case 5:{
                if(pila->empty()){
                    cout<<FG_Red<<"No se puede mostrar el tope por que la pila esta vacia\n"<<FG_White;
                }else{
                    pila->currentTope();
                }
                break;
            }
            case 6: {
                if(pila->empty()){
                    cout<<FG_Red<<"No se puede vaciar por que la pila ya esta vacia\n"<<FG_White;
                }else{
                    pila->clean();
                    cout<<FG_Green<<"Todos los elementos de la pila fuero eliminados exitosamente\n"<<FG_White;
                }
                break;
			}
            case 7: {
                cout<<"\nThanks for using it!\n\n";
                loop = false;
                break;
            }
            default:
                cout << FG_Red << "Opcion no valida, ingrese una que se encuentre en el rango!" << FG_White << endl;
                break;
        }
        cout<<"\nPress ENTER to continue ... ";
        cin.get();
        cin.get();
    }
    return 0;
}
