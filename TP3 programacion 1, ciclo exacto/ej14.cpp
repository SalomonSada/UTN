#include <iostream>
using namespace std;

int main() {
/** 14) Hacer un programa para ingresar una lista de 8 números y luego informar si todos están
    como crecientes.
    Por ejemplo si la lista fuera:
    Ejemplo 1: -10, 1, 5, 7, 15, 18, 20, 23 se emitirá un cartel: “Conjunto Ordenado”
    Ejemplo 2: 10, 10, 15, 20, 25, 25, 28, 33 se emitirá un cartel: “Conjunto Ordenado”
    Ejemplo 3: 10, 1, 15, 7, -15, 18, 20, 23 se emitirá un cartel: “Conjunto No Ordenado”    */
    int n, counter=0, na;
    for (int i=0; i<8; i++) {
        cin >> n;
        if (i==0) na = n;
        if (n>=na) counter++;
        na = n;
    }
    if (counter == 8) cout<<"\n\nConjunto Ordenado \n\n";
    else cout<<"\n\nConjunto no ordenado \n\n";
    return 0;
}
