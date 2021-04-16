#include <iostream>
using namespace std;

int main() {
/** 6) Hacer un programa para ingresar un N valor que indica la cantidad de números que
    componen una lista y luego solicitar se ingresen esos N números. Se pide informar cuantos
    son positivos.
    Ejemplo: Se ingresa como valor N un 5, y luego se ingresa: 10, -3, 2, 5, 4. Se listará
    Cantidad de Positivos: 4
    Ejemplo: Se ingresa como valor N un 6, y luego se ingresa: -10, -3, -2, 0, -5, -4. Se listará
    Cantidad de Positivos: 0    */

    int length;  /// => cantidad de numeros que contendra la lista
    int n; /// => numeros dentro de la lista (el tamaño de la lista esta definido por "length")
    int counter; /// => numeros positivos dentro de la lista

    cout << "Ingrese cantidad de numeros que almacenara la lista: ";
    cin >> length; cout << endl;

    for (int i = 0; i < length; i++) {
        cout << i+1 << ") Ingrese un numero: ";
        cin >> n;
        if (n > 0) { /// se infiere que el 0 es neutro, no positivo
            counter++;
        }
    }

    cout << "\n\n La cantidad de numeros positivos es: " << counter << "\n\n";
    return 0;
}
