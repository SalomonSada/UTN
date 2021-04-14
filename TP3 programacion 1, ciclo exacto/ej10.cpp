#include <iostream>
using namespace std;

int main() {
    int numeros;
    int mayor = -8888;
    int menor = 8888;
    cout << "Ingresar 10 numeros:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese numero: ";
        cin >> numeros;
        if (numeros > mayor) {
            mayor = numeros;
        }
        if (numeros < menor) {
            menor = numeros;
        }
    }

    cout << "\nEl maximo es: " << mayor;
    cout << "\nEl minimo es: " << menor;
    return 0;
}
