#include <iostream>
using namespace std;

int main() {
/** 8) Hacer un programa para ingresar una lista de 10 n�meros, luego informar el m�ximo.
    Ejemplo: 5, 10, 20, 8, 25, 13, 35, -8, -5, 20. Se listar� M�ximo 35.
    Ejemplo: 5, 10, 20, 8, 55, 13, 55, -8, -5, 20. Se listar� M�ximo 55.

    9) Hacer un programa para ingresar una lista de 10 n�meros, luego informar el m�ximo y
    la posici�n del m�ximo en la lista. En caso de �empates� considerar la primera aparici�n.
    Ejemplo: 5, -10, 20, 8, 25, 13, 35, -8, -5, 20. Se listar� M�ximo 35 Posici�n 7.
    Ejemplo: 5, -10, 20, 8, 25, 13, 55, -8, 55, 20. Se listar� M�ximo 55 Posici�n 7.    */

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
