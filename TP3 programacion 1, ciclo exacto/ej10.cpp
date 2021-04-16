#include <iostream>
using namespace std;

int main() {
/** 10) Hacer un programa para ingresar una lista de 10 n�meros, luego informar el m�ximo y
    el m�nimo.
    Ejemplo: 10, 20, -5, 30,-15, 5, 42, 0, 22, -13. Se listar� M�ximo 42 M�nimo -15.
    Ejemplo: 10, 20, 5, 30, 15, 5, 42, 8, 22, 13. Se listar� M�ximo 42 M�nimo 5.
    Ejemplo: -10, -20, -5, -30, -15, -12, -42, -8, -22, -13. Se listar� M�ximo -5 M�nimo -42.
    Observe que los tres ejemplos dejan en claro que la idea de que el m�ximo
    �seguramente� es un positivo y el m�nimo �seguramente� es un negativo, queda
    totalmente descartada.  */

    int numeros;
    int mayor = -8888888;
    int menor =  8888888;
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
