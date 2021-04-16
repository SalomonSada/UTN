#include <iostream>
using namespace std;

int main() {
/** 5) Hacer un programa para que el usuario ingrese dos números y luego el programa
    muestre por pantalla los números entre el menor y el mayor de ambos.
    Ejemplo, si el usuario ingresa 3 y 15, se mostrarán los números entre el 3 y el 15; y si el
    usuario ingresa 25 y 8, se mostrarán los números entre el 8 y el 25.    */
    int a, b;
    cout << "Ingresar valor de A: ";
    cin >> a;
    cout << "\nIngresar valor de B: ";
    cin >> b; cout << "\n\n";  // Nota: lo que hace el: "\n"  es hacer un salto de linea, lo mismo que un "endl"

    if (a <= b) {
        cout << "De 'A' hasta 'B': ";
        for (a, b; a <= b; a++) {
            cout << a << ",";
        }
    }
    else {
        cout << "De 'B' hasta 'A': ";
        for (a, b; b<= a; b++) {
            cout << b << ",";
        }
    }
    cout << endl;
    return 0;
}
