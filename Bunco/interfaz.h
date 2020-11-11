#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

void menu() {
    cout<<"::::: Bienvenido a jugar Bunco ::::: \n\n Escoja el numero de la opcion que desea seleccionar: \n\n";
    cout<<"1) Juego nuevo para UN jugador. \n2) Juego nuevo para DOS jugadores. \n3) Mostrar puntacion mas alta. \n";
    cout<<"4) Modo simulado (carga de datos manual). \n5) Salir. \n\n Ingresar: " ;
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

void finJuego_2jugadores(string name, int puntaje, int buncos, int fallos, int lanzamientos)   {
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
