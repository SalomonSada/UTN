#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "rlutil.h"
using namespace rlutil;
using namespace std;

#include "interfaz.h"
//#define ENTER 13

int presioneEnter() {
    while (true) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == ENTER) return 1;
        }
    }
}

void cargarDados(int v[], int tam, int limite){
    locate(33,14);cout<<"A lanzar los dados, presione ENTER, BUENA SUERTE!!";
    presioneEnter();
    srand(time(NULL));
    for(int i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
    }
}

void cargarDadosSimulado(int dados[], int tam) {
    locate(37,14); cout<<"Ingresar los dados:";
    for (int i=0; i<tam*2; i+=2) {
        locate(57+i,14);
        cin>>dados[i/2];
    }
}

void mostrarDados(int dados[]) {
    dadoPosuno(dados[0]); dadoPosDos(dados[1]); dadoPosTres(dados[2]);
}

int maximo(int v[], int tam) {
    int Max, pos;
    for (int i=0; i<tam; i++) {
        if (i==0) {
            Max=v[i];
            pos=i;
        }
        if (v[i]>Max) {
            Max=v[i];
            pos=i;
        }
    }
    return pos;
}

void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int bunco(int dados[], int tam, int ronda) {
    int buncos=0;
    for (int i=0; i<tam; i++) if (dados[i]==ronda) buncos++;
    if (buncos==3) return 21;
    return 0;
}

int repetidos (int dados[]) {
    if (dados[0]==dados[1] && dados[1]==dados[2]) return 5;
    return 0;
}

int divisible5(int dados[], int tam) {
    int suma=0;
    for (int i=0; i<tam; i++) suma+=dados[i];
    if (suma%5==0) return 3;
    return 0;
}

int escalera (int dados[], int tam) {
    ordenarVector(dados, tam);
    if (dados[2]-dados[1]==1 && dados[1]-dados[0]==1) return 2;
    return 0;
}

int coincidenciaConRonda (int dados[], int tam, int ronda) {
    int coincidencias=0;
    for (int i=0; i<tam; i++) if (dados[i]==ronda) coincidencias++;
    if (coincidencias==2) return 2;
    if (coincidencias==1) return 1;
    return 0;
}

int evaluarDados (int dados[], int tam, int ronda) {
    int puntos[5], pos;

    puntos[0] = bunco(dados, tam, ronda);
    puntos[1] = repetidos(dados);
    puntos[2] = divisible5(dados, tam);
    puntos[3] = escalera(dados, tam);
    puntos[4] = coincidenciaConRonda(dados, tam, ronda);

    pos = maximo(puntos, 5);

    locate(42,21); cout<<"PUNTAJE TIRADA: "<<puntos[pos];
    locate(42,22); cout<<"       SACASTE: ";
    if (puntos[pos] != 0) {
        switch (pos) {
            case 0: cout<<"BUNCO!!!  \n\n";
                break;
            case 1: cout<<"3 REPETIDOS DISTINTOS DE LA RONDA  \n\n";
                break;
            case 2: cout<<"SUMA DIVISIBLE POR 5  \n\n";
                break;
            case 3: cout<<"ESCALERA  \n\n";
                break;
            case 4: cout<<"COINCIDENCIA CON RONDA  \n\n";
                break;
        }
    }
    else cout<<"TIRO FALLIDO \n\n";
    return puntos[pos];
}

#endif // FUNCIONES_H_INCLUDED
