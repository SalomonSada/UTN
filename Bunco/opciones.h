#ifndef OPCIONES_H_INCLUDED
#define OPCIONES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <tuple>
using namespace std;

#include "funciones.h"
#include "interfaz.h"

/** Reglas del bunco:
    6 rondas, del 1 al 6. ---->  Para comenzar c/ronda se lanzan tres dados. Acorde a los resultados, tendra un puntaje y se vera si sigue lanzando:
    .................................................................................
    PUNTAJE:
    21 pts --> 3 dados iguales al numero de ronda.
     5 pts --> 3 dados iguales (pero distintos al numero de ronda)
     3 pts --> la suma de los tres dados es divisible entre cinco
     2 pts --> Si los tres dados forman una escalera
     1 pt  -->  Por cada coincidencia con el numero de la ronda
    NOTA: Si mas de una de estas condicionantes suceden, se tomara en cuenta solo la que mayor puntaje le de al jugador
    .................................................................................
    ¿CUANTO DURA UN TURNO EN LA MODALIDAD DOS JUGADORES?
    DOS JUGADORES ---> hasta que el puntaje sumado sea >= 21 ó tenga un tiro fallido
    .................................................................................
    ¿CUANDO TERMINA UNA RONDA?
       UN JUGADOR ---> hasta que el puntaje sumado sea >= 21. Los tiros fallidos se cuentan para restar 3 puntos al final por cada uno.
    DOS JUGADORES ---> El primer jugador que sume un puntaje >= 21.
    En caso de que el primer jugador cumpla esa condicion en el primer turno. El segundo jugador tiene la oportunidad de usar su turno. */

tuple<int, int> jugar(string name, string name2, int jugadores, bool azar) {
    int dados[3], i, d;
    int result;

/// -----> Player 1 <-----
    int puntaje1=0;
    int totalBuncos=0;
    int fallido=0;
    int lanzamiento1 = 1;

/// -----> Player 2 <-----
    int puntaje2=0;
    int totalBuncos2=0;
    int lanzamiento2 = 1;

    for (i=1; i<=6; i++) {
        bool nextRound = false;
        int puntaje_x_Ronda1=0, puntaje_x_Ronda2=0;
        int turno=1;   /// -----> Solo para la version de dos jugadores

       while (nextRound == false) {
            bool turno_player_1=true, turno_player_2=true;
            int puntaje_x_turno1=0, puntaje_x_turno2=0;

///     ------------> Turno player 1 <------------
            while (turno_player_1==true) {
                infoTurno(name, i,puntaje1,totalBuncos,lanzamiento1, puntaje_x_turno1);
                lanzamiento1++;

///         --------> Tirar los dados segun modalidad <--------
                if (azar==false) {
                    cargarDadosSimulado(dados, 3);
                }
                else {
                    cargarDados(dados, 3, 6);
                    mostrarDados(dados, 3);
                }

///         ---------------> Evaluar los dados <---------------
                result = evaluarDados(dados, 3, i);
                puntaje_x_turno1 += result;
                if (result==21) totalBuncos++;
                if (result==0)  {
                    fallido++;
                    if (jugadores==2) {
                        turno_player_1=false;  /// ---> pasamos turno al siguiente jugador <---
                    }
                }

///         ---------> Pasar al siguiente turno o ronda <----------
                if (jugadores==1) {
                    if (puntaje_x_turno1 >= 21) turno_player_1=false;
                }
                else {
                    if (puntaje_x_turno1+puntaje_x_Ronda1 >= 21) turno_player_1=false;
                }

                ptsRonda(puntaje_x_Ronda1+puntaje_x_turno1);
                system("pause");
                system("cls");
            }

///     -----> Salimos del turno de player 1 <-----
            puntaje_x_Ronda1+=puntaje_x_turno1;
            puntaje1+=puntaje_x_turno1;
///     -----> Cerramos la ronda para modo UN jugador <-----
            if (jugadores==1) {
                nextRound=true;
    //       puntaje1+=puntaje_x_Ronda1;
                entreRonda_1jugador(name,i,puntaje1,totalBuncos,fallido,lanzamiento1);
            }

///      ||..................... MODO DOS JUGADORES .....................||
            else {
          //      puntaje_x_Ronda1+=puntaje_x_turno1;
          //      puntaje1+=puntaje_x_turno1;
                entreRonda_2jugadores(name, name2, i, puntaje1, puntaje2, totalBuncos, totalBuncos2, 2);
                if (puntaje_x_Ronda1>=21) {
                    if (turno>1) {
                        turno_player_2 = false;
                        nextRound = true;
                    }
                }

///     ------------> Turno player 2 <------------
                while (turno_player_2==true) {
                    infoTurno(name2, i,puntaje2,totalBuncos2,lanzamiento2, puntaje_x_turno2);
                    lanzamiento2++;

                    if (azar==false) {
                    cargarDadosSimulado(dados, 3);
                    }
                    else {
                        cargarDados(dados, 3, 6);
                        mostrarDados(dados, 3);
                    }

                    result = evaluarDados(dados, 3, i);
                    puntaje_x_turno2+=result;
                    if (result==21) totalBuncos2++;
                    if (result==0)  {
                        fallido++;
                        if (jugadores==2) {
                            turno_player_2=false;
                            cout<<endl<<"MIRA"<<endl;
                        }
                    }

                    if (puntaje_x_turno2+puntaje_x_Ronda2 >= 21) turno_player_2=false;

                    ptsRonda(puntaje_x_Ronda2+puntaje_x_turno2);
                    system("pause");
                    system("cls");
                }

///         -----> Salimos del turno de player 2 <-----
                puntaje_x_Ronda2+=puntaje_x_turno2;
                puntaje2+=puntaje_x_turno2;

///         -----> Mostramos info entre turno si corresponde <-----
                if (nextRound==false) {
                    entreRonda_2jugadores(name, name2, i, puntaje1, puntaje2, totalBuncos, totalBuncos2, 1);
                }
///         -----> Cerramos la Ronda para el modo DOS jugadores <-----
                if (puntaje_x_Ronda1>=21 || puntaje_x_Ronda2>=21) nextRound = true;
                turno++;
            }
        }
    }
    if (jugadores==1) {
        puntaje1-=(fallido*2);
        finJuego_1jugador(name,puntaje1,totalBuncos,fallido,lanzamiento1-1);
        return make_tuple(puntaje1, 1);
    }
    else {
        if (puntaje1>puntaje2) {
            finJuego_2jugadores(name, puntaje1, totalBuncos);
            return make_tuple(puntaje1, 1); /// gana player 1
        }
        else if (puntaje2>puntaje1) {
            finJuego_2jugadores(name2, puntaje2, totalBuncos2);
            return make_tuple(puntaje2, 2); /// gana player 2
        }
        else {
            return make_tuple(0, 0); /// empate
        }
    }
}

void higher() {
    cout<<"Puntaje mas alto: \n\n"<<"Nombre del jugador: "<<"XXX"<<" | Cantidad de Buncos (Esto sera una variable) \n\n";
    system("pause");
    system("cls");
}


#endif // OPCIONES_H_INCLUDED
