#include <iostream>
using namespace std;

int main() {
/** 3) Hacer un programa para mostrar por pantalla los números del 20 al 1 en orden
    decreciente.
    Importante: El programa no tiene ningún ingreso de datos. */
    for (int a = 20; a >= 1; a--) {
        cout << a << ",";
    }
    cout << endl;
    return 0;
}
