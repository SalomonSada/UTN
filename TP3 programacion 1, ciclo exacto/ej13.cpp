#include <iostream>
using namespace std;

int main() {
/** 12) Dada una lista de 7 números informar cual es el primer y segundo número impar ingresado.
    Ejemplo 8, 4, 5, 6, -9, 5,7 se informa 5 y -9.  */
    int numeros, impar1, impar2;
    int counter = 0;

    cout << "Ingresar 7 numeros:\n\n";

    for (int i = 0; i < 7; i++) {
        cout << i + 1 << ") Ingrese numero: ";
        cin >> numeros;

        if (numeros % 2 != 0 || numeros == 1) {
            counter++;
            if (counter == 1) {
                impar1 = numeros;
            }
            else if (counter == 2) {
                impar2 = numeros;
            }
        }


    }
    cout << " \nEl primer numero impar es: " << impar1;
    cout << "\nEl ultimo numero impar es: " << impar2;

    return 0;
}
