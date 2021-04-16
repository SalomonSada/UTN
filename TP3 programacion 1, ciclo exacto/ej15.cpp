#include <iostream>
using namespace std;

int main() {
/** 15) Hacer un programa para ingresar 5 números, luego informar los 2 mayores valores
    ingresados, aclarando cual es el máximo y cual el que le sigue.
    Ejemplo: 10, 8, 12, 14, 3 el resultado será 14 y 12.
    Ejemplo: 14, 8, 12, 14 ,3 el resultado será 14 y 14.
    Ejemplo: -4, -8, -12, -20, -2 el resultado será -2 y -4     */
    int num, Max, Max2;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ") Ingrese un numero: ";
        cin >> num;
        if (i==0) {
            Max = num;
            Max2 = num;
        }
        else {
            if (num >= Max) {
                Max2 = Max;
                Max = num;
            }
            else if (num >= Max2) {
                Max2 = num;
            }
        }
    }
    cout << endl << Max << endl << Max2 << endl;
    return 0;
}
