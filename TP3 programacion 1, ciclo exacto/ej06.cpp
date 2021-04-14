#include <iostream>
using namespace std;

int main() {
    int length;  /// => cantidad de numeros que contendra la lista
    int positivos; /// => numeros dentro de la lista (el tamaño de la lista esta definido por "length")
    int counter; /// => numeros positivos dentro de la lista

    cout << "Ingrese cantidad de numeros que almacenara la lista: ";
    cin >> length; cout << endl;

    for (int i = 0; i < length; i++) {
        cout << i+1 << ") Ingrese un numero: ";
        cin >> positivos;
        if (positivos > 0) {
            counter++;
        }


    }

    cout << "\n\n La cantidad de numeros positivos es: " << counter << "\n\n";
    return 0;
}
