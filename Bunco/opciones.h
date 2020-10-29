#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

void jugar() {

}
void onePlayer() {
    cout<<"Aca se jugara con UN jugador \n\n";
    system("pause");
    system("cls");
}

void twoPlayer() {
    cout<<"Aca se jugara con DOS jugador \n\n";
    system("pause");
    system("cls");
}

void higher() {
    cout<<"Puntaje mas alto: \n\n"<<"Nombre del jugador: "<<"XXX"<<" | Cantidad de Buncos (Esto sera una variable) \n\n";
    system("pause");
    system("cls");
}

void simular() {
    cout<<"Aca jugaras en el modo simulado \n\n";
    system("pause");
    system("cls");
}

void menu() {
    cout<<"::::: Bienvenido a jugar Bunco ::::: \n\n Escoja el numero de la opcion que desea seleccionar: \n\n";
    cout<<"1) Juego nuevo para UN jugador. \n2) Juego nuevo para DOS jugadores. \n3) Puntacion mas alta. \n";
    cout<<"4) Modo simulado (carga de datos manual). \n5) Salir. \n\n Ingresar: " ;
}

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
/// Opcion 1 jugador:
int jugar(string name, string name2, int jugadores, bool azar) {
    int dados[3], i, d;
    /// Datos para Player 1:
    int puntaje1=0;
    int totalBuncos=0;
    int fallido=0;
    cout<<"Bienvenido, "<<name<<"! \n\n";
    /// Datos para Player 2:
    int puntaje2=0;
    int totalBuncos2=0;
    int fallido2=0;
    if (jugadores==2) {
        cout<<"Bienvenido, "<<name2<<"! \n\n";
    }
    system("pause");
    system("cls");

    for (i=1; i<=6; i++) {
        bool nextRound = false;
        int turno = 1;
        /// Datos Player 1:
        int puntaje1Ronda=0;
        /// Datos Player 2:
        int puntaje2Ronda=0;

       while (nextRound == false) {
            /// Ejecutamos el turno de Player 1:
            bool turno1=true, turno2=true;
            while (puntaje1Ronda < 21 && turno1==true) {
                cout<<"Turno de "<<name<<": \n\n";
                int bunco=0;
                int semi_bunco=0;
                int suma_dados=0;
                cout<<"Ingresa los tres dados: \n";
                /// Cargar los dados, si no es la version simulada se hace una funcion que genere el numero al azar.
                for (d=0; d<3; d++) cin>>dados[d];

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
                    puntaje1Ronda+=5;
                }
                /// 3 pts
                else if (suma_dados % 5 == 0 && bunco<3) {  /// (bunco < 3) porque 5*3= 15, multiplo de 5. en ese caso hay que sumar 21, no 3
                    cout<<"Haz ganado 3 puntos! \n\n";
                    puntaje1Ronda+=3;
                }
                /// 21 pts ó 2pts ó 1 pt
                else if (bunco > 0) {
                    switch (bunco) {
                        case 3:
                            cout<<"Haz Sacado bunco, lacrita! 21 pts \n\n";
                            puntaje1Ronda+=21;
                            totalBuncos++;
                        break;
                        case 2:
                            cout<<"Haz sacado 2 puntos! \n\n";
                            puntaje1Ronda+=2;
                        break;
                        case 1:
                            cout<<"Haz sacado 1 punto! \n\n";
                            puntaje1Ronda+=1;
                        break;
                    }
                }
                else {
                    fallido++;
                    cout<<"Tiro fallido \n\n";
                    /// Pasamos el turno al siguiente jugador en caso de la modalidad DOS jugadores
                    if (jugadores==2) {
                        turno1=false;
                    }
                }
                system("pause");
                system("cls");
            }
            /// Mostramos puntaje de player 1 (Esto hay que adjustarlo acorde a la interfaz que indican)
            puntaje1+=puntaje1Ronda;
            cout<<"............................ \n";
            cout<<":::     RONDA Nro "<<i<<"      ::: \n";
            cout<<"::: PUNTAJE "<<name<<": "<<puntaje1<<"  ::: \n";
            cout<<":::     Buncos:  "<<totalBuncos<<"       ::: \n............................ \n\n";
            system("pause");
            system("cls");
            /// Cerramos la ronda para modo UN jugador
            if (jugadores==1) {
                if (puntaje1Ronda>=21) nextRound = true;
            }
            else {
                if (turno==1) {

                }
            }
/// ||..................... MODO DOS JUGADORES .....................||

            if (jugadores==2) {
                /// ejecutamos el turno del Player 2:
                while (puntaje2Ronda < 21 && turno2==true) {
                    cout<<"Turno de "<<name2<<": \n\n";
                    int bunco=0;
                    int semi_bunco=0;
                    int suma_dados=0;
                    cout<<"Ingresa los tres dados: \n";
                    /// Cargar los dados, si no es la version simulada se hace una funcion que genere el numero al azar.
                    for (d=0; d<3; d++) cin>>dados[d];

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
                        puntaje2Ronda+=5;
                    }
                    /// 3 pts
                    else if (suma_dados % 5 == 0 && bunco<3) {  /// (bunco < 3) porque 5*3= 15, multiplo de 5. en ese caso hay que sumar 21, no 3
                        cout<<"Haz ganado 3 puntos! \n\n";
                        puntaje2Ronda+=3;
                    }
                    /// 21 pts ó 2pts ó 1 pt
                    else if (bunco > 0) {
                        switch (bunco) {
                            case 3:
                                cout<<"Haz Sacado bunco, lacrita! 21 pts \n\n";
                                puntaje2Ronda+=21;
                                totalBuncos2++;
                            break;
                            case 2:
                                cout<<"Haz sacado 2 puntos! \n\n";
                                puntaje2Ronda+=2;
                            break;
                            case 1:
                                cout<<"Haz sacado 1 punto! \n\n";
                                puntaje2Ronda+=1;
                            break;
                        }
                    }
                    else {
                        fallido2++;
                        cout<<"Tiro fallido \n\n";
                        turno2=false;
                    }
                    system("pause");
                    system("cls");
                }
                /// Mostramos puntaje de player 2 (Esto hay que adjustarlo acorde a la interfaz que indican)
                puntaje2+=puntaje2Ronda;
                cout<<"............................ \n";
                cout<<":::     RONDA Nro "<<i<<"      ::: \n";
                cout<<"::: PUNTAJE "<<name2<<": "<<puntaje2<<"  ::: \n";
                cout<<":::     Buncos:  "<<totalBuncos2<<"       ::: \n............................ \n\n";
                system("pause");
                system("cls");
                /// Cerramos la Ronda:

            }
                /// Cerramos la Ronda para el caso de ser UN solo jugador:


        }
    }
    /// Restamos los tiros fallidos para la version de Un jugador
    cout<<"PUNTAJE FINAL antes de restar los tiros fallidos: "<<puntaje1<<"\n Cantidad de tiros fallidos: "<<fallido<<"\n\n";
    puntaje1-=(fallido*3);
    cout<<"PUNTAJE FINAL despues de restar los tiros fallidos: "<<puntaje1<<"\n\n";
    return puntaje1;
}
#endif // FUNCIONES_H_INCLUDED
