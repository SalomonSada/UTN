#include <iostream>
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
/**  Solucion sin Arrays:

#include <iostream>
using namespace std;

int main()  {
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
    cout << "\nEl primer numero par es: " << par << " || y su posicioin es: " << posicionPar;
    cout << "\n\nEl ultimo numero primo es: " << primo << " || y su posicioin es: " << posicionPrimo << endl;
    return 0;
}
*/
