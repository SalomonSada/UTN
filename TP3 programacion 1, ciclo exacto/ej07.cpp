#include <iostream>
using namespace std;

int main() {
    int counterPositivo = 0, counterNegativo = 0, counterCero = 0, i = 0, numeros;
    cout << "Ingresar 10 numeros:\n";

    for (i; i < 10; i++) {
        cout << "\nIngrese numero: ";
        cin >> numeros;

        if (numeros > 0) {
            counterPositivo++;
        }
        else if (numeros < 0) {
            counterNegativo++;
        }
        else {
            counterCero++;
        }

    }

    cout << "\n\nNumeros positivos: " << counterPositivo;
    cout << "\n\nNumeros cero: " << counterCero;
    cout << "\n\nNumeros negativos: " << counterNegativo << "\n\n";
    return 0;
}
