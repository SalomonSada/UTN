#include <iostream>
using namespace std;

int main() {
/** 4) Hacer un programa para que el usuario ingrese un número positivo y que luego se
    muestren por pantalla los números entre el 1 y el número ingresado por el usuario.
    Ejemplo. Si el usuario ingresa 15, se mostrarán los números entre el 1 y el 15. */
    int a;
    cout << "Ingresar valor de a: ";
    cin >> a; cout << "\n\n";
    for (int i = 1; i <= a; i++) {
       cout << i << ",";
    }
    cout << "\n\n";
    return 0;
}
