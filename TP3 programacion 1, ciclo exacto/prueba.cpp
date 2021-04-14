#include <iostream>
using namespace std;

int main()  {
    int numero;
    int primo, cPrimo = 0, posicionPrimo;
    int par, cPar, posicionPar;
    cout << "ingresar 7 numeros: \n\n";

    for (int i = 1; i <= 7; i++) {
        cout << endl << i << ") Ingresar un numero: ";
        cin >> numero;
        /// => PRIMER PAR:
        if (numero % 2 == 0) {
            cPar++;
            if (cPar == 1) {
                par = numero;
                posicionPar = i;
            }
        }
        /// => ULTIMO PRIMO:
        for (int j = 1; j <= numero; j++) {
            if (numero % j == 0) {
                cPrimo++;
                if (cPrimo == 2) {
                    primo = numero;
                    posicionPrimo = i;
                }
            }
        cout << "valor de p: " << j <<  " | contador de divisores: " << cPrimo << " | Primo: " << primo << endl;

        }
        cPrimo = 0;
    }
    cout << "\nEl primer numero par es: " << par << " || y su posicioin es: " << posicionPar;
    cout << "\n\nEl ultimo numero primo es: " << primo << " || y su posicioin es: " << posicionPrimo << endl;
    return 0;
}
