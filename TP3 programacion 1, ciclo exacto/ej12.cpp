#include <iostream>
using namespace std;

int main() {
    int numeros, impar1, impar2;
    int counter;

    cout << "Ingresar 7 numeros:\n\n";

    for (int i = 0; i < 7; i++) {
        cout << i + 1 << ") Ingrese numero: ";
        cin >> numeros;

        if (numeros % 2 != 0 || numeros == 1) {
            counter += 1;
        }
        if (counter == 1 && numeros % 2 != 0) {
        impar1 = numeros;
        }
        else if (counter == 2 && numeros % 2 != 0) {
            impar2 = numeros;
        }

    }
    cout << " \nEl primer numero impar es: " << impar1;
    cout << "\nEl segundo numero impar es: " << impar2;


    return 0;
}
