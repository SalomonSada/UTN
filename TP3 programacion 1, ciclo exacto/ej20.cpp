#include <iostream>
using namespace std;

int main() {
/** 20) Se define como divisores propios de un número a aquellos que son sus divisores
    excluyendo al número en sí mismo.
    Ejemplo. Los divisores propios del 4 son: 1 y 2.
    Ejemplo. Los divisores propios del 12 son; 1, 2, 3, 4 y 6.
    Se define a un número como perfecto cuando la suma de todos sus divisores propios
    coincide con el número en sí mismo.
    Ejemplo: 6 es número perfecto pues 1+2+3=6
    Ejemplo: 28 es número perfecto pues 1+2+4+7+14=28
    Ejemplo: 12 no es número perfecto pues 1+2+3+4+6=16
    Hacer un programa para ingresar un número y luego informar con un cartel aclaratorio si el
    mismo es un número perfecto o es número no perfecto.     */

int num, counter, perfecto;
    cout << "-.INGRESAR UN NUMERO: ";
    cin >> num;
    int div[num];

    for (int i = 1; i < num + 1; i++) {
        if (i != num && num % i == 0) {
            div[counter] = {i};
            counter++;
        }
    }
    for (int i = 0; i < counter; i++) {
        perfecto += div[i];
    }
    if (perfecto == num) {
        cout << "\n ES PERFECTO: *SI*\n\n";
    }   else {
        cout << "\n ES PERFECTO: *NO*\n\n";
    }

    return 0;
}
