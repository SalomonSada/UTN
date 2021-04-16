#include <iostream>
using namespace std;

int main() {
/** 11) Hacer un programa para ingresar una lista 10 números e informar el máximo de los
    negativos y el mínimo de los positivos.
    Ejemplo: 5, 8, 12, 2, -10, 15, -20, 8, -3, 24. Máximo Negativo -3. Mínimo Positivo 2.    */
    int numeros;
    int mayor = -8888;
    int menor = 8888;
    cout << "Ingresar 10 numeros:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese numero: ";
        cin >> numeros;
        if (numeros > 0 && numeros < menor) {
                menor = numeros;
        }
        if (numeros < 0 && numeros > mayor) {
                mayor = numeros;
        }
    }

     cout << "\nEl maximo de los negativos es: " << mayor;
    cout << "\nEl minimo de los positivos es:  " << menor << endl;
    return 0;
}
