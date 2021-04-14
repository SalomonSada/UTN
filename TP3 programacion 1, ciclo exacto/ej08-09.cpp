#include <iostream>
using namespace std;

int main() {
    int numeros;
    int mayor;
    int posicion;
    cout << "Ingresar 10 numeros:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "- Ingrese numero: ";
        cin >> numeros;
        if (numeros > mayor) {
            mayor = numeros;
            posicion = i+1;
        }
    }
    cout << "\n El maximo de la lista es: " << mayor << " y su posicion es: " << posicion << endl;
    return 0;
}
