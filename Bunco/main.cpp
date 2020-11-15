#include <iostream>
#include <cstdlib>
#include <tuple>
#include <conio.h>
#include <cstring>

#include "rlutil.h"
#include "opciones.h"
#include "funciones.h"
#include "interfaz.h"
using namespace std;
using namespace rlutil;

#define ABAJO 80
#define ARRIBA 72
#define ENTER 13

int main () {
    /// para usar en menu, y parametros
    int opciones;
    string nombre[2];

    /// almacenar los datos que devolveran las funciones
    int puntaje=0, buncos;
    string nombreJ;

    /// almacenar los datos del jugador con el puntaje mas alto
    int puntajeGanador=0, buncosGanador;
    string nombreGanador;

    while (true) {
        opciones=menu();
         system("cls");
        switch(opciones) {
            case 9: {
                cout<<"Bienvenido!! \n\nIngrese su nombre: ";
                cin>>nombre[0];
                system("cls");

                auto resultado = jugar(nombre[0], "", 1, true);
                puntaje = get<0>(resultado);
                nombreJ = get<1>(resultado);
                buncos = get<2>(resultado);
            break;
            }
            case 10: {
                cout<<"Bienvenido!! \n\nIngrese nombre del jugador 1: ";
                cin>>nombre[0];
                cout<<"\n\n"<<"Ingrese nombre del jugador 2: ";
                cin>>nombre[1];
                system("cls");
                auto resultado = jugar(nombre[0], nombre[1], 2, true);
                puntaje = get<0>(resultado);
                nombreJ = get<1>(resultado);
                buncos = get<2>(resultado);
            break;
            }
            case 11:
                higher(puntajeGanador, nombreGanador, buncosGanador);
            break;

            case 12: {
                cout<<"Bienvenido!! \n\nIngrese su nombre: ";
                cin>>nombre[0];
                system("cls");
                auto resultado = jugar(nombre[0], "", 1, false); /// True a revisar
                puntaje = get<0>(resultado);
                nombreJ = get<1>(resultado);
                buncos = get<2>(resultado);
            break;
            }

            case 13:
                salir();
                return 0;
            break;
        }

        if (puntaje>puntajeGanador) {
            puntajeGanador=puntaje;
            buncosGanador=buncos;
            nombreGanador=nombreJ;
        }
    }
}
