#ifndef OPCIONES_H_INCLUDED
#define OPCIONES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <tuple>
using namespace std;

#include "funciones.h"

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
    /// Datos para Player 1:
    int puntaje1=0;   /// puntaje total
    int totalBuncos=0;
    int fallido=0;
    int lanzamiento1 = 1;
    /// Datos para Player 2:
    int puntaje2=0;
    int totalBuncos2=0;
    int lanzamiento2 = 1;

    for (i=1; i<=6; i++) {
        bool nextRound = false;
        int turno = 1;         ///  ----> Turno (solo se usa para la version de DOS jugadores)
        int puntaje_x_Ronda1=0, puntaje_x_Ronda2=0;

       while (nextRound == false) {

            bool turno1=true, turno2=true;
            int puntaje_x_turno1=0, puntaje_x_turno2=0;
            /// Ejecutamos el turno de Player 1:
            while (turno1==true) {
                /// Mostramos los datos (esto debe estar como la interfaz indicada, verla en el archivo de funciones)
                infoTurno(name, i,puntaje1,totalBuncos,lanzamiento1, puntaje_x_Ronda1);
                lanzamiento1++;
                int bunco=0;
                int semi_bunco=0;
                int suma_dados=0;

                /// Acorde al modo de juego, cargamos los dados
                if (azar==false) {
                    /// Version Simulada:
                    cout<<"Ingresa los tres dados: \n";
                    for (d=0; d<3; d++) cin>>dados[d];
                }
                else {
                    /// Version Azar:
                    cout<<"A lanzar los dados, BUENA SUERTE!! \n\n";
                    system("pause");
                    cargarAleatorio(dados, 3, 6);
                    cout<<endl<<"Haz sacado: ";
                    for (d=0; d<3; d++) cout<<dados[d]<<", ";
                    cout<<endl;
                }

                for (d=0; d<3; d++) {
                    /// 21 pts o 2pts o 1 pt
                    if (dados[d] == i) bunco++;
                    /// 5 pts
                    else if (d != 2 && dados[d] == dados[d+1]) semi_bunco++;
                    /// 3 pts
                    suma_dados+=dados[d];
                }

                /// 5 pts
                if (semi_bunco == 2) {
                    cout<<"\n 5 puntos! \n\n";
                    puntaje_x_turno1+=5;
                }
                /// 3 pts
                else if (suma_dados % 5 == 0 && bunco<3) {  /// (bunco < 3) porque 5*3= 15, multiplo de 5. en ese caso hay que sumar 21, no 3
                    cout<<"\n 3 puntos! \n\n";
                    puntaje_x_turno1+=3;
                }
                /// 21 pts ó 2pts ó 1 pt
                else if (bunco > 0) {
                    switch (bunco) {
                        case 3:
                            cout<<"\n BUNCO!!  21 pts \n\n";
                            puntaje_x_turno1+=21;
                            totalBuncos++;
                        break;
                        case 2:
                            cout<<"\n 2 puntos! \n\n";
                            puntaje_x_turno1+=2;
                        break;
                        case 1:
                            cout<<"\n 1 punto! \n\n";
                            puntaje_x_turno1+=1;
                        break;
                    }
                }
                else {
                    fallido++;
                    cout<<"\nTiro fallido \n\n";
                    /// Pasamos el turno al siguiente jugador en caso de la modalidad DOS jugadores
                    if (jugadores==2) {
                        turno1=false;
                    }
                }
                /// corte del ciclo while, para pasar al siguiente turno o ronda. segun la modalidad:
                if (jugadores==1) {
                    if (puntaje_x_turno1 >= 21) turno1=false;
                    ptsRonda(puntaje_x_turno1);
                }
                else {
                    ptsRonda(puntaje_x_turno1);
                    if (puntaje_x_turno1+puntaje_x_Ronda1 >= 21) turno1=false;
                }
                system("pause");
                system("cls");
            }

            puntaje_x_Ronda1+=puntaje_x_turno1;
            /// Cerramos la ronda para modo UN jugador
            if (jugadores==1) {
                nextRound=true;
                /// Mostramos info entre turno (Esto hay que adjustarlo acorde a la interfaz que indican)
                puntaje1+=puntaje_x_Ronda1;
                entreRonda_1jugador(name,i,puntaje1,totalBuncos,fallido,lanzamiento1);
            }




            /// ||..................... MODO DOS JUGADORES .....................||
            else {
                /// Sumamos los puntos
                puntaje_x_Ronda1+=puntaje_x_turno1;
                puntaje1+=puntaje_x_turno1;
                ///Mostramos info entre turno
                entreRonda_2jugadores(name, name2, i, puntaje1, puntaje2, totalBuncos, totalBuncos2, 2);
                /// Pasamos el turno del jugador UNO al jugador DOS. Acorde a si es el primer turno de la ronda o no
                if (puntaje_x_Ronda1>=21) {
                    if (turno>1) {
                        turno2 = false;
                        nextRound = true;
                    }
                }


                /// ejecutar el turno del Player 2:
                while (turno2==true) {
                    /// Mostramos los datos (esto debe estar como la interfaz indicada, verla en el archivo de funciones)
                    infoTurno(name2, i,puntaje2,totalBuncos2,lanzamiento2, puntaje_x_Ronda2);
                    lanzamiento2++;

                    int bunco=0;
                    int semi_bunco=0;
                    int suma_dados=0;

                    if (azar==false) {
                        /// Version Simulada:
                        cout<<"Ingresa los tres dados: \n";
                        for (d=0; d<3; d++) cin>>dados[d];
                    }
                    else {
                        /// Version Azar:
                        cout<<"A lanzar los dados, BUENA SUERTE!! \n\n";
                        system("pause");
                        cargarAleatorio(dados, 3, 6);
                        cout<<endl<<"Haz sacado: ";
                        for (d=0; d<3; d++) cout<<dados[d]<<", ";
                        cout<<endl;
                    }

                    for (d=0; d<3; d++) {
                        /// 21 pts o 2pts o 1 pt
                        if (dados[d] == i) bunco++;
                        /// 5 pts
                        else if (d != 2 && dados[d] == dados[d+1]) semi_bunco++;
                        /// 3 pts
                        suma_dados+=dados[d];
                    }
                    /// 5 pts
                    if (semi_bunco == 2) {
                        cout<<"Haz sacado un semi-bunco! \n\n";
                        puntaje_x_turno2+=5;
                        ptsRonda(puntaje_x_Ronda2);
                    }
                    /// 3 pts
                    else if (suma_dados % 5 == 0 && bunco<3) {  /// (bunco < 3) porque 5*3= 15, multiplo de 5. en ese caso hay que sumar 21, no 3
                        cout<<"Haz ganado 3 puntos! \n\n";
                        puntaje_x_turno2+=3;
                    }
                    /// 21 pts ó 2pts ó 1 pt
                    else if (bunco > 0) {
                        switch (bunco) {
                            case 3:
                                cout<<"Haz Sacado bunco, lacrita! 21 pts \n\n";
                                puntaje_x_turno2+=21;
                                totalBuncos2++;
                            break;
                            case 2:
                                cout<<"Haz sacado 2 puntos! \n\n";
                                puntaje_x_turno2+=2;
                            break;
                            case 1:
                                cout<<"Haz sacado 1 punto! \n\n";
                                puntaje_x_turno2+=1;
                            break;
                        }
                    }
                    else {
                        cout<<"Tiro fallido \n\n";
                        turno2=false;
                    }

                    ptsRonda(puntaje_x_turno2);
                    if (puntaje_x_turno2+puntaje_x_Ronda2 >= 21) turno2=false;
                    system("pause");
                    system("cls");
                }

                /// Sumamos los puntos
                puntaje_x_Ronda2+=puntaje_x_turno2;
                puntaje2+=puntaje_x_turno2;
                /// Mostramos info entre turno si corresponde
                if (nextRound==false) {
                    entreRonda_2jugadores(name, name2, i, puntaje1, puntaje2, totalBuncos, totalBuncos2, 1);
                }
                /// Cerramos la Ronda para el modo DOS jugadores:
                if (puntaje_x_Ronda1>=21 || puntaje_x_Ronda2>=21) nextRound = true;
                turno++;
            }
        }
    }
    if (jugadores==1) {
        /// Restamos los tiros fallidos para la version de Un jugador
        puntaje1-=(fallido*3);
        system("cls");
        return make_tuple(puntaje1, 1);
    }
    else {
        if (puntaje1>puntaje2) {
            return make_tuple(puntaje1, 1); /// gana player 1
        }
        else if (puntaje2>puntaje1) {
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
