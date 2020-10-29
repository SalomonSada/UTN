#include <iostream>
#include <cstdlib>

using namespace std;
#include "opciones.h"

int main () {
    int opciones;
    /// Para usar en la funcion jugar()
    string name[2];
    int puntaje, jugadores;

    menu();
    cin>>opciones;

    while (true) {
        switch(opciones) {
            case 1:
                system("cls");
                cout<<"Bienvenido!! \n\nIngrese su nombre: ";
                cin>>name[0];
                system("cls");
                jugar(name[0], "", 1, true); /// True a revisar
                ///onePlayer();
            break;

            case 2:
                system("cls");
                cout<<"Bienvenido!! \n\nIngrese nombre del jugador 1: ";
                cin>>name[0];
                cout<<"\n\n"<<"Ingrese nombre del jugador 2: ";
                cin>>name[1];
                system("cls");
                jugar(name[0], name[1], 2, true); /// True a revisar
                ///twoPlayer();
            break;

            case 3:
                system("cls");
                higher();
            break;

            case 4:
                system("cls");
                simular();
            break;

            case 5:
                system("cls");
                cout<<"Gracias por usar nuestro programa. \n\n";
                return 0;
            break;
        }
        /// Caso de ingresar un dato equivocado:
        if (opciones < 1 || opciones > 5) {
            cout<<"\n\n"<<"Haz escogido "<<opciones<<". Selecciona una opcion valida, por favor. \n\n";
            system("pause");
            system("cls");
        }
        /// Al terminar de ejecutar la opcion seleccionada en el men�, se muestra nuevamente:
        menu();
        cin>>opciones;
    }


    return 0;
}
