#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#define ABAJO 80
#define ARRIBA 72
#define ENTER 13

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


    gotoxy(x, y); cout<<"*"; //a partir de aca es para utilizar las flechas del teclado
    while (true) {
        if (_kbhit()) {
            gotoxy(x, y); cout<<" ";
            char tecla = _getch();
            if (tecla == ENTER) {
                setBackgroundColor(BLACK);
                setColor(WHITE);
                return y;
            }
            if (tecla == ARRIBA && y > 9) y--;
            if (tecla == ABAJO && y < 13) y++;
            gotoxy(x, y); cout<<"*";
        }
    }
}

void infoTurno(string name, int ronda, int puntaje, int buncos, int lanzamientos, int puntos){
    cout<<"TURNO DE "<<name<<" | RONDA NRO "<<ronda<<" | PUNTAJE ACUMULADO: "<<puntaje+puntos<<endl;
    cout<<"------------------------------------------------------- \n";
    cout<<"VECES QUE OBTUVO BUNCO: "<<buncos<<endl;
    cout<<"------------------------------------------------------- \n";
    cout<<"LANZAMIENTO NRO "<<lanzamientos<<"\n";
    cout<<"------------------------------------------------------- \n\n";
}

void ptsRonda(int puntaje) {
    cout<<"***************************    \n";
    cout<<"| PUNTAJE DE LA RONDA: "<<puntaje<<" | \n";
    cout<<"*************************** \n\n";
}

void entreRonda_1jugador(string name, int ronda, int puntaje, int buncos, int fallos, int lanzamientos)   {
    cout<<"------------------------------ \n";
    cout<<"        RONDA Nro "<<ronda<<"\n";
    cout<<"------------------------------ \n";
    cout<<"    PUNTAJE "<<name<<":"<<puntaje<<" PUNTOS     \n";
    cout<<"          Buncos:  "<<buncos<<"           \n";
    cout<<"      Tiradas Fallidas:"<<fallos<<"     \n";
    cout<<"        Lanzamientos:"<<lanzamientos<<"       \n";
    cout<<"------------------------------ \n\n\n";
    system("pause");
    system("cls");
}

void finJuego_1jugador(string name, int puntaje, int buncos, int fallos, int lanzamientos)   {
    cout<<"         FELICIDADES!! \n";
    cout<<"------------------------------ \n";
    cout<<"        JUGADOR: "<<name<<"\n";
    cout<<"------------------------------ \n";
    cout<<"          BUNCOS:  "<<buncos<<"           \n";
    cout<<"      TIRADAS FALLIDAS:"<<fallos<<"     \n";
    cout<<"        LANZAMIENTOS:"<<lanzamientos<<"       \n";
    cout<<"------------------------------ \n";
    cout<<"      PUNTAJE TOTAL: "<<puntaje<<"\n";
    cout<<"------------------------------ \n\n\n";
    system("pause");
    system("cls");
}

void entreRonda_2jugadores(string name1, string name2, int ronda, int puntaje1, int puntaje2, int buncos1, int buncos2, int proxTurno) {
    cout<<"------------------------------ \n";
    cout<<"        RONDA Nro "<<ronda<<"\n";
    cout<<"    PROXIMO TURNO: ";
    if (proxTurno==1) cout<<name1;
    else cout<<name2;
    cout<<"\n------------------------------ \n";
    cout<<"  PUNTAJE "<<name1<<": "<<puntaje1<<" PUNTOS \n";
    cout<<"    CANTIDAD DE BUNCOS: "<<buncos1<<endl;
    cout<<"------------------------------ \n";
    cout<<"  PUNTAJE "<<name2<<": "<<puntaje2<<" PUNTOS \n";
    cout<<"    CANTIDAD DE BUNCOS: "<<buncos2<<endl;
    cout<<"------------------------------ \n\n\n";
    system("pause");
    system("cls");
}

void finJuego_2jugadores(string name, int puntaje, int buncos)   {
    cout<<"         FELICIDADES!! \n";
    cout<<"------------------------------ \n";
    cout<<"        JUGADOR: "<<name<<"\n";
    cout<<"------------------------------ \n";
    cout<<"          BUNCOS:  "<<buncos<<"           \n";
    cout<<"------------------------------ \n";
    cout<<"      PUNTAJE TOTAL: "<<puntaje<<"\n";
    cout<<"------------------------------ \n\n\n";
    system("pause");
    system("cls");
}


#endif // INTERFAZ_H_INCLUDED
