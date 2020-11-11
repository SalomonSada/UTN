#include <iostream>
#include <cstdlib>
#include <tuple>
#include <time.h>

using namespace std;
#include "opciones.h"
#include "funciones.h"
#include "interfaz.h"

int main () {
    int opciones;
    string name[2];
    int puntaje, jugadores; /// ---> high score

    menu();
    cin>>opciones;
    system("cls");
    while (true) {
        switch(opciones) {
            case 1: {
                cout<<"Bienvenido!! \n\nIngrese su nombre: ";
                cin>>name[0];
                system("cls");

                auto resultado = jugar(name[0], "", 1, true);
                puntaje = get<0>(resultado);
                jugadores = get<1>(resultado);
            break;
            }
            case 2: {
                cout<<"Bienvenido!! \n\nIngrese nombre del jugador 1: ";
                cin>>name[0];
                cout<<"\n\n"<<"Ingrese nombre del jugador 2: ";
                cin>>name[1];
                system("cls");
                auto resultado = jugar(name[0], name[1], 2, true);
                puntaje = get<0>(resultado);
                jugadores = get<1>(resultado);
            break;
            }
            case 3:
                higher();
            break;

            case 4: {
                cout<<"Bienvenido!! \n\nIngrese su nombre: ";
                cin>>name[0];
                system("cls");
                auto resultado = jugar(name[0], "", 1, false); /// True a revisar
                puntaje = get<0>(resultado);
                jugadores = get<1>(resultado);
            break;
            }

            case 5:
                cout<<"Gracias por usar nuestro programa. \n\n";
                return 0;
            break;
        }
        /// Caso de ingresar un dato equivocado:
        if (opciones < 1 || opciones > 5) {
            cout<<"\n\n"<<"Haz escogido "<<opciones<<". Selecciona una opcion valida, por favor. \n\n";
            system("pause");
            system("cls");
        }
        menu();
        cin>>opciones;
    }
    return 0;
}
