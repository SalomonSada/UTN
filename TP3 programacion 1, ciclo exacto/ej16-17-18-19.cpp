#include <iostream>
using namespace std;

int main() {
    int num, counter;
    cout << "-.INGRESAR UN NUMERO: ";
    cin >> num;
    int div[num];

    for (int i = 1; i < num + 1; i++) {
        if (num % i == 0) {  /// Agregar "i % 2 == 0 &&" dentro del if para solo devolver los divisores pares => Ej 17
            div[counter] = {i};
            counter++;
        }
    }
    for (int i = 0; i < counter; i++) {
        cout << endl << div[i] << endl;
    }

    cout << "______________________________________________________\n" << "\n*Nro DIVISORES: " << counter << "\n"; /// Ej 18

    if (counter == 2) { /// Ej 19
        cout << "\n*ES PRIMO: **SI**\n";
    }   else {
        cout << "\n*ES PRIMO: **NO**\n";
    }

    return 0;
}

/** int numero, primo, cPrimo = 0;
    cin >> numero;

    for (int i = 1; i < numero + 1; i++) {
        if (numero % i == 0) {
            cPrimo++;
        }
    }

    if (cPrimo == 2) {
        primo = numero;
    }

    cout << "\n El ultimo primo es: " <<  primo; ///<< " || Su posicion es: " << posicionPrimo << "\n"; */
