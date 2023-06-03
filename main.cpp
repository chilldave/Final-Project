    #include <iostream>
    #include <unistd.h>
    #include "pila_cola.h"
    #include "colors.h"

    using namespace std;

    int main(){

        Pila* pila = new Pila();
        Cola* cola = new Cola();

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
                    std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;

                    if(pila->empty())
                    {
                        cout<<FG_Red<<"\n\t\tNo se puede eliminar por que la pila esta vacia\n"<<FG_White;
                    }else{
                        // pila->pop();
                        pila->pop2();
                    }
                    break;
                }
                case 3: {
                    system("figlet -c -t -k Byte Band: Pila");
                    if (pila->empty()) {
                        std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;
                        cout<<FG_Red<<"\n\t\tNo se puede actualizar ninguna informacion por que la pila esta vacia\n"<<FG_White;
                    } else {
                        string valor;
                        string dato;
                        pila->print();
                        std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;

                        cout << "\n\n\t\tIngrese el valor que desea actualizar : "; 
                        cin.ignore();
                        getline(cin,valor,'\n');// index;

                        CopyUntilSpecData(*pila,*cola,valor);
                        std::cout<<"\n";
                        std::cout<<"\n\n\t\tEsto es la pila\n";
                        // std::cout<< FG_Orange <<"----------------------------------------------------------------------"<<FG_White<<std::endl;
                        pila->print();
                        std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;
                        std::cout<<"\n\n\t\tEsto es la cola\n";
                        // std::cout<< FG_Orange <<"\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;
                        cola->cPrint();

                        if(!pila->empty()){
                            std::string elemento = pila->pop();
                            std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;

                            cout << "\n\n\t\tIngrese el nuevo dato para " << FG_Yellow <<valor << FG_White <<": ";
                            fflush(stdin);
                            getline(cin, dato, '\n');
                            pila->push(dato);
                        }

                        cola->reverse();
                        returnQueueToStack(*pila,*cola);
                        
                        std::cout<<"\n\n\t\tEsto es la pila";
                        pila->print();
                        std::cout<<"\n\n\t\tEsto es la cola";
                        cola->cPrint();
                    }

                    break;
                }
                case 4: {
                    system("figlet -c -t -k Byte Band: Pila");

                    if(pila->empty())
                    {
                        std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;
                        cout<<FG_Red<<"\n\t\tNo se puede mostrar ninguna informacion por que la pila esta vacia\n"<<FG_White;
                    }else{
                        cout<<"\n\t\tTodos los elementos de la pila: \n";
                        pila->print();
                    }
                    break;
                }
                case 5:{
                    system("figlet -c -t -k Byte Band: Pila");
                    if(pila->empty()){
                        std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;
                        cout<<FG_Red<<"\n\t\tNo se puede mostrar el tope por que la pila esta vacia\n"<<FG_White;
                    }else{
                        pila->currentTope();
                    }
                    break;
                }
                case 6: {
                    system("figlet -c -t -k Byte Band: Pila");
                    std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------\n"<<FG_White<<std::endl;

                    if(pila->empty()){
                        cout<<FG_Red<<"\t\tNo se puede vaciar por que la pila ya esta vacia\n"<<FG_White;
                    }else{
                        pila->clean();
                        cout<<FG_Green<<"\t\tTodos los elementos de la pila fuero eliminados exitosamente\n"<<FG_White;
                    }
                    break;
                }
                case 7: {
                    system("figlet -c -t -k Byte Band: Pila");
                    std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;
                    cout<<FG_Green<<"\n\t\t\t\t\tGracias por su atencion!\n"<<FG_Green;
                    loop = false;
                    break;
                }
                default:
                    system("figlet -c -t -k Byte Band: Pila");
                    std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;
                    cout << FG_Red << "\n\t\tOpcion no valida, ingrese una que se encuentre en el rango!" << FG_White << endl;
                    break;
            }
                std::cout<< FG_Orange <<"\n\t\t----------------------------------------------------------------------"<<FG_White<<std::endl;

            cout<<"\n\t\tPress ENTER to continue ... ";
            cin.get();
            cin.get();
        }
        delete pila;
        delete cola;

        return 0;
    }
