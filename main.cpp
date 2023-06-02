#include <iostream>
#include <unistd.h>
#include "pila_cola.h"
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
        cout<<"\t\t\t7. Mostrar Cola\n";
        cout<<"\t\t\t8. Salir\n";
        cout<<endl<<FG_White;
        cout<<"\t\t\tElija una opcion(1-8): ";
        cin>>opc;

        int _opcint = 0;
        try {
           _opcint = stoi(opc);
        } catch (const invalid_argument & e) {}

        system("clear");
        switch(_opcint){
            case 1: {
                system("figlet -c -t -k Byte Band: Pila");
                string dato;
                cout<<"\n\t\tIngrese el nuevo dato a almacenar en la pila: ";
				cin.ignore();
				getline(cin, dato);
                pila->push(dato);
                break;
            }
            case 2: {
                system("figlet -c -t -k Byte Band: Pila");
                if(pila->empty())
                {
                    cout<<FG_Red<<"\n\t\tNo se puede eliminar por que la pila esta vacia\n"<<FG_White;
                }else{
                    pila->pop();
                }
                break;
            }
			case 3: {
                system("figlet -c -t -k Byte Band: Pila");
				if (pila->empty()) {
                    cout<<FG_Red<<"\n\t\tNo se puede actualizar ninguna informacion por que la pila esta vacia\n"<<FG_White;
				} else {
					string index;
					string dato;
                    pila->print();
					cout << "\n\n\t\tIngrese el valor que desea actualizar : "; 
                    cin.ignore();
                    getline(cin,index,'\n');// index;
                    pila->update(index);
                    
					/* cout << "\n\n\t\tIngrese el nuevo dato para " << index << ": ";
					cin.ignore();
					getline(cin, dato);
					pila->update(index,dato); */
				}
				break;
			}
            case 4: {
                system("figlet -c -t -k Byte Band: Pila");
                if(pila->empty())
                {
                    cout<<FG_Red<<"\n\t\tNo se puede mostrar ninguna informacion por que la pila esta vacia\n"<<FG_White;
                }else{
                    cout<<"\n\t\todos los elementos de la pila: \n";
                    pila->print();
                }
                break;
            }
            case 5:{
                system("figlet -c -t -k Byte Band: Pila");
                if(pila->empty()){
                    cout<<FG_Red<<"\n\t\tNo se puede mostrar el tope por que la pila esta vacia\n"<<FG_White;
                }else{
                    pila->currentTope();
                }
                break;
            }
            case 6: {
                system("figlet -c -t -k Byte Band: Pila");
                if(pila->empty()){
                    cout<<FG_Red<<"\n\t\tNo se puede vaciar por que la pila ya esta vacia\n"<<FG_White;
                }else{
                    pila->clean();
                    cout<<FG_Green<<"\n\t\tTodos los elementos de la pila fuero eliminados exitosamente\n"<<FG_White;
                }
                break;
			}
            case 7:{
                system("figlet -c -t -k Byte Band: Pila");
                pila->cPrint();
                break;
            }
            case 8: {
                system("figlet -c -t -k Byte Band: Pila");
                cout<<"\n\t\t\t  Gracias por usar la aplicacion!\n\n";
                loop = false;
                break;
            }
            default:
                system("figlet -c -t -k Byte Band: Pila");
                cout << FG_Red << "\n\t\tOpcion no valida, ingrese una que se encuentre en el rango!" << FG_White << endl;
                break;
        }
        cout<<"\n\n\t\tPress ENTER to continue ... ";
        cin.get();
        cin.get();
    }
    return 0;
}
