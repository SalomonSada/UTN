#include <iostream>
using namespace std;

int main()  {
    /** 21) Dada una lista de 7 n�meros informar el primer n�mero par ingresado y su ubicaci�n en
    la lista y el �ltimo de los n�meros primos y su ubicaci�n en la lista.
    Ejemplo 7, 4, 5, 6, 9, 13, 10 se informa Primer n�mero par: 4 ubicaci�n 2. Ultimo primo:
    13 ubicaci�n 6.
    Ejemplo 9, 5, 21, 9, 13, 15, 6 se informa Primer n�mero par: 6 ubicaci�n 7. Ultimo primo:
    13 ubicaci�n 5. */

    int numero;
    int primo, cPrimo, posicionPrimo;
    int par, cPar, posicionPar;
    cout << "ingresar 7 numeros: \n\n";

    for (int i = 1; i <= 7; i++) {
        cout << i << ") Ingresar un numero: ";
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
            }
        }
        if (cPrimo == 2) {
            primo = numero;
            posicionPrimo = i;
        }
        cPrimo = 0;
    }
    cout << "\nEl primer numero par es: " << par << " || y su posicion es: " << posicionPar;
    cout << "\n\nEl ultimo numero primo es: " << primo << " || y su posicioin es: " << posicionPrimo << endl;
    return 0;
}

/** Solucion con Arrays:
include <iostream>
using namespace std;

int main()  {

    int numero;
    int par[7], posicionPar[7], cPar;
    int primo,  posicionPrimo,  cPrimo[7];
    cout << "Ingresar 7 numeros: \n\n";

    for (int i = 1; i <= 7; i++) {
        cout << i << ") Ingresar numero: ";
        cin >> numero;
        cout << endl << cPrimo[i] << endl;
        /// => PRIMER PAR:
        if (numero % 2 == 0) {
            par[cPar] = {numero};
            posicionPar[cPar] = {i};
            cPar++;
        }
        /// => ULTIMO PRIMO:
        for (int j = 1; j <= numero; j++) {
           if (numero % j == 0) {
                cPrimo[i]++;
            }
        }
        if (cPrimo[i] == 2) {
            primo = numero;
            posicionPrimo = i;
        }
    }
    cout << "\n El primer par es: " <<  par[0] << " || Su posicion es: " << posicionPar[0] << "\n";
    cout << "\n El ultimo primo es: " <<  primo << " || Su posicion es: " << posicionPrimo << "\n";
    return 0;
}
*/
