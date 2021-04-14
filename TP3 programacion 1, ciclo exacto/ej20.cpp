#include <iostream>
using namespace std;

int main() {
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

/**

    int numero;
    int cPrimo = 0;
    cout << "-.INGRESAR UN NUMERO: ";
    cin >> numero;

    for (int j = 1; j <= numero; j++) {
        if (numero % j == 0) {
            cPrimo++;
        }
    }
    if (cPrimo == 2) {
        cout << "\nEl numero es primo\n";
    }   else {
            cout << "\nEl numero NO es primo\n";
        }
*/
