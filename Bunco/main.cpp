#include <iostream>
#include <cstdlib>
#include <tuple>
#include <time.h>
#include <conio.h>
#include <cstring>

#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "opciones.h"
#include "funciones.h"
#include "interfaz.h"


#define ABAJO 80
#define ARRIBA 72
#define ENTER 13

int main () {
    int opciones;
    string name[2];
    int puntaje, jugadores; /// ---> high score

    while (true) {
        opciones=menu();
        system("cls");
        switch(opciones) {
            case 9: {
                cout<<"Bienvenido!! \n\nIngrese su nombre: ";
                cin>>name[0];
                system("cls");

                auto resultado = jugar(name[0], "", 1, true);
                puntaje = get<0>(resultado);
                jugadores = get<1>(resultado);
            break;
            }
            case 10: {
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
            case 11:
                higher();
            break;

            case 12: {
                cout<<"Bienvenido!! \n\nIngrese su nombre: ";
                cin>>name[0];
                system("cls");
                auto resultado = jugar(name[0], "", 1, false); /// True a revisar
                puntaje = get<0>(resultado);
                jugadores = get<1>(resultado);
            break;
            }

            case 13:
                cout<<"Gracias por usar nuestro programa. \n\n";
                return 0;
            break;
        }

    }
    return 0;
}
