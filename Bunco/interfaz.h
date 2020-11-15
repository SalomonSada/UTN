#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#define ABAJO 80
#define ARRIBA 72
#define ENTER 13
#include "rlutil.h"
using namespace rlutil;

void tituloAnimado() {
    int xcol;
    char vtitulo[] = "   BIENVENIDOS A JUGAR BUNCO   ";
        // primera linea
        setColor(YELLOW);
        setBackgroundColor(RED);
        gotoxy(10, 2); printf("%c", 201);
        gotoxy(10, 3); printf("%c", 177);
        gotoxy(10, 4); printf("%c", 200);


        for (xcol = 11; xcol < 100; xcol++) {
            gotoxy(xcol, 2); printf("%c", 205);
            gotoxy(xcol, 4); printf("%c", 205);
            if(xcol==70) {
                gotoxy(40, 3); cout<<vtitulo;
                gotoxy(39, 2); printf("%c", 203);
                gotoxy(39, 3); printf("%c", 178);
                gotoxy(39, 4); printf("%c", 202);
                gotoxy(70, 2); printf("%c", 203);
                gotoxy(70, 3); printf("%c", 178);
                gotoxy(70, 4); printf("%c", 202);
            }
            Sleep(1);
        }
        gotoxy(100, 2); printf("%c", 187);
        gotoxy(100, 3); printf("%c", 177);
        gotoxy(100, 4); printf("%c", 188);

}

int menu() {
    int x = 35, y = 9;
    tituloAnimado();
    setBackgroundColor(LIGHTRED);
    setColor(YELLOW);
    gotoxy(35, 8);  cout << "                                            " << endl;
    gotoxy(35, 9);  cout << "   1-Juego nuevo para UN jugador            " << endl;
    gotoxy(35, 10); cout << "   2-Juego nuevo para DOS jugadores         " << endl;
    gotoxy(35, 11); cout << "   3-Mostrar puntuacion mas alta            " << endl;
    gotoxy(35, 12); cout << "   4-Modo simulado (carga de datos manual)  " << endl;
    gotoxy(35, 13); cout << "   5-SALIR                                  " << endl;
    gotoxy(35, 14); cout << "                                            " << endl;

    gotoxy(31, 17); cout << "     Produced By: Salomon, Sofia y Estanislao     ";
    gotoxy(31, 18); cout << "                                                  " << endl;
    gotoxy(31, 19); cout << "        Menu creado usando libreria RLUTIL        ";


    gotoxy(x, y); printf(" %c", 16); //a partir de aca es para utilizar las flechas del teclado
    while (true) {
        if (_kbhit()) {
            gotoxy(x, y); cout<<"   ";
            char tecla = _getch();
            if (tecla == ENTER) {
                setBackgroundColor(BLACK);
                setColor(WHITE);
                return y;
            }
            if (tecla == ARRIBA && y > 9) y--;
            if (tecla == ABAJO && y < 13) y++;
            gotoxy(x, y); printf(" %c", 16);
        }
    }
}

void infoTurno(string name, int ronda, int puntaje, int buncos, int lanzamientos, int puntos){
    int xcol;
    for (xcol = 25; xcol < 90; xcol++) {
        locate(xcol, 7); printf("%c", 205);
        locate(xcol, 13); printf("%c", 205);
        locate(xcol, 9); printf("%c", 205);
        locate(xcol, 11); printf("%c", 205);

        if(xcol==70) {
            locate(30, 8); cout<<"  TURNO DE "<<name<<" | RONDA NRO "<<ronda<<" | PUNTAJE ACUMULADO: "<<puntaje+puntos;
            locate(25, 7); printf("%c", 201);
            locate(90, 7); printf("%c", 187);
            locate(25, 8); printf("%c", 186);
            locate(90, 8); printf("%c", 186);

            //locate(26, 9); cout<<"----------------------------------------------------------------\n";
            locate(25, 7); printf("%c", 205);
            locate(25, 9); printf("%c", 204);
            locate(90, 9); printf("%c", 185);

            locate(25, 10); cout<<"                     VECES QUE OBTUVO BUNCO:"<<buncos<<"                    \n";
            locate(25, 7); printf("%c", 201);
            locate(25, 10); printf("%c", 186);
            locate(90, 10); printf("%c", 186);

            locate(25, 7); printf("%c", 201);
            locate(25, 11); printf("%c", 204);
            locate(90, 11); printf("%c", 185);

            locate(25, 12); cout<<"                         LANZAMIENTO NRO "<<lanzamientos<<"                      \n";
            locate(25, 7); printf("%c", 201);
            locate(25, 12); printf("%c", 186);
            locate(90, 12); printf("%c", 186);
            locate(90, 13); printf("%c", 188);
            locate(25, 13); printf("%c", 200);
        }
    }
    setColor(WHITE);
    setBackgroundColor(BLACK);
}

void ptsRonda(int puntaje) {
    int xcol;

    for (xcol = 40; xcol < 75; xcol++) {
        locate(xcol, 24); printf("%c", 205);
        locate(xcol, 26); printf("%c", 205);
        if(xcol==70) {
            locate(30, 7); printf("%c", 205);
            locate(40, 25); cout<<"       PUNTAJE DE LA RONDA: "<<puntaje<<"      \n";
            locate(40, 25); printf("%c", 186);
            locate(40, 24); printf("%c", 201);
            locate(40, 26); printf("%c", 200);
            locate(75, 24); printf("%c", 187);
            locate(75, 25); printf("%c", 186);
            locate(75, 26); printf("%c", 188);
        }
    }
    locate(35, 27);  cout << "";
    locate(35, 28);  cout << "";
    locate(35, 29);  cout << "";
    locate(35, 30);  cout << "";

    setColor(WHITE);
    setBackgroundColor(BLACK);
}

void entreRonda_1jugador(string name, int ronda, int puntaje, int buncos, int fallos, int lanzamientos)   {
    int xcol;
                for (xcol = 25; xcol < 90; xcol++) {
                locate(xcol, 7); printf("%c", 205);
                locate(xcol, 15); printf("%c", 205);
                locate(xcol, 9); printf("%c", 205);
                locate(xcol, 11); printf("%c", 205);
                locate(xcol, 13); printf("%c", 205);
                locate(xcol, 17); printf("%c", 205);

                if(xcol==70) {
                locate(25, 8); cout<<"                             RONDA Nro"<<ronda<<"                          \n";
                locate(25, 7); printf("%c", 201);
                locate(90, 7); printf("%c", 187);
                locate(25, 8); printf("%c", 186);
                locate(90, 8); printf("%c", 186);

                locate(25, 7); printf("%c", 205);
                locate(25, 9); printf("%c", 204);
                locate(90, 9); printf("%c", 185);

                locate(25, 10); cout<<"                       PUNTAJE "<<name<<":"<<puntaje<<" PUNTOS                    \n";
                locate(25, 7); printf("%c", 201);
                locate(25, 10); printf("%c", 186);
                locate(90, 10); printf("%c", 186);

                locate(25, 7); printf("%c", 201);
                locate(25, 11); printf("%c", 204);
                locate(90, 11); printf("%c", 185);

                locate(25, 12); cout<<"                              Buncos:"<<buncos<<"                            \n";
                locate(25, 7); printf("%c", 201);
                locate(25, 12); printf("%c", 186);
                locate(90, 12); printf("%c", 186);

                locate(25, 14); cout<<"                         Tiradas Fallidas:"<<fallos<<"                       \n";
                locate(25, 13); printf("%c", 204);
                locate(25, 15); printf("%c", 204);
                locate(90, 15); printf("%c", 185);
                locate(90, 13); printf("%c", 185);

                locate(25, 16); cout<<"                          Lanzamientos:"<<lanzamientos<<"                         \n";
                locate(25, 14); printf("%c", 186);
                locate(90, 14); printf("%c", 186);
                locate(25, 17); printf("%c", 200);
                locate(90, 17); printf("%c", 188);
                locate(25, 16); printf("%c", 186);
                locate(90, 16); printf("%c", 186);

                }
               // Sleep(1);
                }
                locate(35, 20);  cout << "";
                locate(35, 21);  cout << "";
                locate(35, 22);  cout << "";
                locate(35, 23);  cout << "";
    system("pause");
    system("cls");
}

void finJuego_1jugador(string name, int puntaje, int buncos, int fallos, int lanzamientos)   {
    int xcol;
    setBackgroundColor(BLACK);
    setColor(WHITE);
    for (xcol = 40; xcol < 75; xcol++) {
        locate(xcol, 24); printf("%c", 205);
        locate(xcol, 26); printf("%c", 205);

        locate(40, 25); cout<<"       PUNTAJE TOTAL: "<<puntaje<<"    \n";
        locate(40, 25); printf("%c", 186);
        locate(40, 24); printf("%c", 201);
        locate(40, 26); printf("%c", 200);
        locate(75, 24); printf("%c", 187);
        locate(75, 25); printf("%c", 186);
        locate(75, 26); printf("%c", 188);
    }
    for (xcol = 52; xcol < 66;xcol++){
        locate(53, 4); cout<<"FELICIDADES!!\n";
        locate(xcol, 3); printf("%c", 205);
        locate(xcol, 5); printf("%c", 205);
    }
    for (xcol = 25; xcol < 90; xcol++) {
        locate(xcol, 7); printf("%c", 205);
        locate(xcol, 9); printf("%c", 205);
        locate(xcol, 11); printf("%c", 205);
        locate(xcol, 13); printf("%c", 205);
        locate(xcol, 15); printf("%c", 205);
        locate(xcol, 17); printf("%c", 205);

        if(xcol==70) {
            locate(52, 3); printf("%c", 201);
            locate(52, 4); printf("%c", 186);
            locate(52, 5); printf("%c", 200);
            locate(66, 3); printf("%c", 187);
            locate(66, 4); printf("%c", 186);
            locate(66, 5); printf("%c", 188);

            locate(25, 8); cout<<"                       PUNTAJE "<<name<<":"<<puntaje<<" PUNTOS                    \n";
            locate(25, 7); printf("%c", 201);
            locate(90, 7); printf("%c", 187);
            locate(25, 8); printf("%c", 186);
            locate(90, 8); printf("%c", 186);

            locate(25, 7); printf("%c", 205);
            locate(25, 9); printf("%c", 204);
            locate(90, 9); printf("%c", 185);

            locate(25, 10); cout<<"                           JUGADOR: "<<name<<"                         \n";
            locate(25, 7); printf("%c", 201);
            locate(25, 10); printf("%c", 186);
            locate(90, 10); printf("%c", 186);

            locate(25, 7); printf("%c", 201);
            locate(25, 11); printf("%c", 204);
            locate(90, 11); printf("%c", 185);


            locate(25, 12); cout<<"                             BUNCOS: "<<buncos<<"                          \n";
            locate(25, 7); printf("%c", 201);
            locate(25, 12); printf("%c", 186);
            locate(90, 12); printf("%c", 186);

            locate(25, 14); cout<<"                         TIRADAS FALLIDAS: "<<fallos<<"                       \n";
            locate(25, 13); printf("%c", 204);
            locate(25, 15); printf("%c", 204);
            locate(90, 15); printf("%c", 185);
            locate(90, 13); printf("%c", 185);

            locate(25, 16); cout<<"                           LANZAMIENTOS: "<<lanzamientos<<"                        \n";
            locate(25, 14); printf("%c", 186);
            locate(90, 14); printf("%c", 186);
            locate(25, 17); printf("%c", 200);
            locate(90, 17); printf("%c", 188);
            locate(25, 16); printf("%c", 186);
            locate(90, 16); printf("%c", 186);

            locate(25, 14); printf("%c", 186);
            locate(90, 14); printf("%c", 186);
            locate(25, 16); printf("%c", 186);
            locate(90, 16); printf("%c", 186);

        }
            Sleep(1);
    }
    locate(2, 26);  cout << "";
    locate(2, 27);  cout << "";
    locate(2, 28);  cout << "";
    locate(2, 29);  cout << "";
    system("pause");
    system("cls");
}

void entreRonda_2jugadores(string name1, string name2, int ronda, int puntaje1, int puntaje2, int buncos1, int buncos2, int proxTurno) {
    int xcol;
                for (xcol = 25; xcol < 90; xcol++) {
                locate(xcol, 7); printf("%c", 205);
                locate(xcol, 15); printf("%c", 205);
            //    locate(xcol, 9); printf("%c", 205);
                locate(xcol, 11); printf("%c", 205);
            //  locate(xcol, 13); printf("%c", 205);
            //    locate(xcol, 17); printf("%c", 205);
                locate(xcol, 19); printf("%c", 205);

                if(xcol==70) {
                locate(25, 8); cout<<"                             RONDA Nro "<<ronda<<"                          \n";
                locate(25, 7); printf("%c", 201);
                locate(90, 7); printf("%c", 187);
                locate(25, 8); printf("%c", 186);
                locate(90, 8); printf("%c", 186);

                locate(25, 7); printf("%c", 205);
                locate(25, 9); printf("%c", 186);
                locate(90, 9); printf("%c", 186);

                locate(25, 10); cout<<"                        PROXIMO TURNO: ";
                locate(25, 7); printf("%c", 201);
                locate(25, 10); printf("%c", 186);
                locate(90, 10); printf("%c", 186);

                if (proxTurno==1){
                    locate(63, 10);cout<<name1;
                }
                else {locate(63, 10); cout<<name2;}

                locate(25, 7); printf("%c", 201);
                locate(25, 11); printf("%c", 204);
                locate(90, 11); printf("%c", 185);


                locate(25, 12); cout<<"                      PUNTAJE "<<name1<<": "<<puntaje1<<" PUNTOS \n";
                locate(25, 7); printf("%c", 201);
                locate(25, 12); printf("%c", 186);
                locate(90, 12); printf("%c", 186);

                locate(25, 14); cout<<"                       CANTIDAD DE BUNCOS: "<<buncos1<<endl;
                locate(25, 13); printf("%c", 186);
                locate(25, 15); printf("%c", 204);
                locate(90, 15); printf("%c", 185);
                locate(90, 13); printf("%c", 186);

                locate(25, 16); cout<<"                      PUNTAJE "<<name2<<": "<<puntaje2<<" PUNTOS \n";
                locate(25, 14); printf("%c", 186);
                locate(90, 14); printf("%c", 186);
                locate(25, 17); printf("%c", 186);
                locate(90, 17); printf("%c", 186);
                locate(25, 16); printf("%c", 186);
                locate(90, 16); printf("%c", 186);

                locate(25, 18);cout<<"                       CANTIDAD DE BUNCOS: "<<buncos2<<endl;
                locate(25, 18); printf("%c", 186);
                locate(25, 19); printf("%c", 200);
                locate(90, 18); printf("%c", 186);
                locate(90, 19); printf("%c", 188);

                }

                }
                locate(35, 20);  cout << "";
                locate(35, 21);  cout << "";
                locate(35, 22);  cout << "";
                locate(35, 23);  cout << "";
    system("pause");
    system("cls");
}

void finJuego_2jugadores(string name, int puntaje, int buncos)   {
    int xcol;
                setBackgroundColor(BLACK);
                setColor(WHITE);
                for (xcol = 52; xcol < 66;xcol++){
                locate(53, 4); cout<<"FELICIDADES!!\n";



                locate(xcol, 3); printf("%c", 205);
                locate(xcol, 5); printf("%c", 205);
                }
                for (xcol = 45; xcol < 74; xcol++) {
                locate(xcol, 7); printf("%c", 205);
                locate(xcol, 9); printf("%c", 205);
                locate(xcol, 11); printf("%c", 205);
                locate(xcol, 13); printf("%c", 205);

                if(xcol==70) {
                locate(25, 12); cout<<"                         PUNTAJE TOTAL: "<<puntaje<<"            \n";
                locate(25, 8); cout<<"                           JUGADOR: "<<name<<"                         \n";
                locate(25, 10); cout<<"                             BUNCOS: "<<buncos<<"                          \n";
                locate(52, 3); printf("%c", 201);
                locate(52, 4); printf("%c", 186);
                locate(52, 5); printf("%c", 200);
                locate(66, 3); printf("%c", 187);
                locate(66, 4); printf("%c", 186);
                locate(66, 5); printf("%c", 188);


                locate(45, 7); printf("%c", 201);
                locate(74, 7); printf("%c", 187);
                locate(45, 8); printf("%c", 186);
                locate(74, 8); printf("%c", 186);

                locate(45, 7); printf("%c", 205);
                locate(45, 9); printf("%c", 204);
                locate(74, 9); printf("%c", 185);


                locate(45, 7); printf("%c", 201);
                locate(45, 10); printf("%c", 186);
                locate(74, 10); printf("%c", 186);

                locate(45, 7); printf("%c", 201);
                locate(45, 11); printf("%c", 204);
                locate(74, 11); printf("%c", 185);



                locate(45, 7); printf("%c", 201);
                locate(45, 12); printf("%c", 186);
                locate(74, 12); printf("%c", 186);

                locate(45, 13); printf("%c", 200);
                locate(74, 13); printf("%c", 188);

                }
                Sleep(1);
                }
                locate(2, 26);  cout << "";
                locate(2, 27);  cout << "";
                locate(2, 28);  cout << "";
                locate(2, 29);  cout << "";

                setColor(WHITE);
                setBackgroundColor(BLACK);

    system("pause");
    system("cls");
}

///             |||............................................DADOS............................................|||

void dadoUno(int x) {
    locate(x+4,18); printf("%c", 254); // medio
}

void dadoDos(int x) {
    locate(x+2,17); printf("%c", 254); // arriba, izquierda
    locate(x+6,19); printf("%c", 254); // abajo, derecha
}

void dadoTres(int x) {
    locate(x+2,17); printf("%c", 254);
    locate(x+4,18); printf("%c", 254);
    locate(x+6,19); printf("%c", 254);
}

void dadoCuatro(int x) {
    locate(x+2,17); printf("%c", 254);
    locate(x+2,19); printf("%c", 254);
    locate(x+6,17); printf("%c", 254);
    locate(x+6,19); printf("%c", 254);
}

void dadoCinco(int x) {
    locate(x+2,17); printf("%c", 254);
    locate(x+4,18); printf("%c", 254);
    locate(x+6,19); printf("%c", 254);
    locate(x+2,19); printf("%c", 254);
    locate(x+6,17); printf("%c", 254);
}

void dadoSeis(int x) {
    locate(x+2,17); printf("%c", 254);
    locate(x+2,19); printf("%c", 254);
    locate(x+2,18); printf("%c", 254);
    locate(x+6,18); printf("%c", 254);
    locate(x+6,17); printf("%c", 254);
    locate(x+6,19); printf("%c", 254);
}

void escogerDado(int posDado, int dado) {
    switch (posDado) {
    case 1:    dadoUno(44+dado);
        break;
    case 2:    dadoDos(44+dado);
        break;
    case 3:   dadoTres(44+dado);
        break;
    case 4: dadoCuatro(44+dado);
        break;
    case 5:  dadoCinco(44+dado);
        break;
    case 6:   dadoSeis(44+dado);
        break;
    }
}
void dadoPosUno(int dado) {
    escogerDado(dado, 0); /// dado = el numero de dado que corresponde mostrar || 0 = posicion a sumar a eje x
    // EJE X
    for (int i = 44; i < 52; i++) {
        locate(i, 16); printf("%c", 196);
        locate(i, 20); printf("%c", 196);
    }
    // EJE Y
    for (int i = 16; i < 20; i++) {
        locate(44, i); printf("%c", 179);
        locate(52, i); printf("%c", 179);
    }
    ///ESQUINAS
    locate(44, 16); printf("%c", 218);
    locate(44, 20); printf("%c", 192);
    locate(52, 16); printf("%c", 191);
    locate(52, 20); printf("%c", 217);
}

void dadoPosDos(int dado) {
    escogerDado(dado, 10); /// dado = el numero de dado que corresponde mostrar || 10 = posicion a sumar a eje x
    // EJE X
    for (int i = 54; i < 62; i++) {
        locate(i, 16); printf("%c", 196);
        locate(i, 20); printf("%c", 196);
    }
    // EJE Y
    for (int i = 16; i < 20; i++) {
        locate(54, i); printf("%c", 179);
        locate(62, i); printf("%c", 179);
    }
    ///ESQUINAS
    locate(54, 16); printf("%c", 218);
    locate(54, 20); printf("%c", 192);
    locate(62, 16); printf("%c", 191);
    locate(62, 20); printf("%c", 217);
}

void dadoPosTres(int dado) {
    escogerDado(dado, 20);  /// dado = el numero de dado que corresponde mostrar || 20 = posicion a sumar a eje x
    // EJE X
for (int i = 64; i < 72; i++) {
        locate(i, 16); printf("%c", 196);
        locate(i, 20); printf("%c", 196);
    }
    // EJE Y
    for (int i = 16; i < 20; i++) {
        locate(64, i); printf("%c", 179);
        locate(72, i); printf("%c", 179);
    }
    // ESQUINAS
    locate(64, 16); printf("%c", 218);
    locate(64, 20); printf("%c", 192);
    locate(72, 16); printf("%c", 191);
    locate(72, 20); printf("%c", 217);
}

void salir() {
    int xcol;
    setColor(YELLOW); setBackgroundColor(RED);
    for (xcol = 45; xcol < 79; xcol++){
        locate(xcol,6); printf("%c",205);
        locate(xcol,8); printf("%c",205);
        locate(xcol,10); printf("%c",205);
    }

    locate(46,7); cout<<"   Gracias por haber jugado!!   ";
    locate(46,9); cout<<" By Sofia, Estanislao & Salom"; printf("%c",162); cout<<"n ";
    locate(45,6); printf("%c",201);
    locate(45,7); printf("%c",186);
    locate(45,8); printf("%c",204);
    locate(45,9); printf("%c",186);
    locate(45,10); printf("%c",200);
    locate(78,6); printf("%c",187);
    locate(78,7); printf("%c",186);
    locate(78,8); printf("%c",185);
    locate(78,9); printf("%c",186);
    locate(78,10); printf("%c",188);

    locate(50,26); cout<<"";
    locate(50,27); cout<<"";
    locate(50,28); cout<<"";
    setColor(WHITE); setBackgroundColor(BLACK);
}

#endif // INTERFAZ_H_INCLUDED
