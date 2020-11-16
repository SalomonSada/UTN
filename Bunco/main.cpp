#include <iostream>
#include <cstdlib>
#include <tuple>
#include <cstring>
#include <time.h>

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

    /// almacenar los datos que devolveran la funcion jugar (...)
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
                nombre[0] = ingresarNombre(1);
                system("cls");

                auto resultado = jugar(nombre[0], "", 1,true);
                puntaje = get<0>(resultado);
                nombreJ = get<1>(resultado);
                buncos = get<2>(resultado);
            break;
            }
            case 10: {
                nombre[0] = ingresarNombre(1);
                nombre[1] = ingresarNombre(2);
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
                cout<<"Desea jugar, de un jugador o dos jugadores? \n\nIngrese la opcion con numeros: ";cin>>opciones; system("cls");

                nombre[0] = ingresarNombre(1);
                if (opciones==1) {
                    system("cls");
                    auto resultado = jugar(nombre[0], "", 1, false);
                    puntaje = get<0>(resultado);
                    nombreJ = get<1>(resultado);
                     buncos = get<2>(resultado);
                }
                if (opciones==2) {
                    nombre[1] = ingresarNombre(2);
                    system("cls");
                    auto resultado = jugar(nombre[0], nombre[1], 2, false);
                    puntaje = get<0>(resultado);
                    nombreJ = get<1>(resultado);
                     buncos = get<2>(resultado);
                }
                system("cls");
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
