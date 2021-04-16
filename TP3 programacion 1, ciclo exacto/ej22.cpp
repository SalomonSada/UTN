#include <iostream>
using namespace std;

int main() {
    int numero[10];
    int impar1[10], impar2[10];
    int duplas;
    cout << "Ingresar 10 numeros: \n\n";

    for (int i = 0; i < 10; i++) {
        cout << i+1 << ") Ingresar numero: ";
        cin >> numero[i];

        if (numero[i] % 2 != 0 && numero[i-1] % 2 != 0) {
            impar1[duplas] = numero[i-1];
            impar2[duplas] = numero[i];
            duplas++;
        }
    }

    for (int i = 0; i < duplas; i++) {
        cout << endl << i+1 << ") Dupla: " << impar1[i] << " | " << impar2[i];
    }

    cout << "\n\nLa cantidad de duplas: " << duplas << endl;
    return 0;
}
