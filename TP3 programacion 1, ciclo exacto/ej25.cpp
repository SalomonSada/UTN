#include <iostream>
using namespace std;

int main() {
    int piezas, sector;
    int piezas1 = 0, piezas2 = 0, piezas3 = 0;
    int p1 = 0, p2 = 0, p3 = 0; /// Posicion
    int a1 = 0, a2 = 0, a3 = 0; /// acumulador de piezas
    cout << "Ingrese precio y clase del articulo:\n\n";

    for (int i = 1; i <= 6; i++) {
        cout << "Operario Nro " << i << ":\n";
        cout << "Piezas defectuosas: "; cin >> piezas;
        cout << "Sector: "; cin >> sector; cout << "\n";

        if (sector == 1) {
            a1 += piezas;
            if (piezas > piezas1) {
                piezas1 = piezas;
                p1 = i;
            }
        }   else if (sector == 2) {
                    a2 += piezas;
                    if (piezas > piezas2) {
                        piezas2 = piezas;
                        p2 = i;
                    }
            }   else if (sector == 3) {
                        a3 += piezas;
                        if (piezas > piezas3) {
                            piezas3 = piezas;
                            p3 = i;
                        }
                }   else if (sector <= 0 || sector > 3) {
                        cout << "\n\Sector no puede ser mayor a 3 ni menor o igual que 0\n\n"; return 0;
                    }
    }
    cout << "Numero de operario con mas piezas defectuosas por sector:\n\n";
    cout << "Sector 1: " << p1 << "\nSector 2: " << p2 << "\nSector 3: " << p3 << "\n\n";
    if (a1 >= a2 && a1 >= a3) {
        cout << "El sector con mayor piezas defectuosas es:  1";
    }   else if (a2 >= a1 && a2 >= a3) {
            cout << "El sector con mayor piezas defectuosas es:  2";
        }   else if (a3 >= a2 && a3 >= a1) {
                cout << "El sector con mayor piezas defectuosas es:  3";
            }
    cout << endl;
    return 0;
}

/// Posicion del operario con mayor cantidad de piezas defectuosas (por sector)
/// Sector donde se totalizo la mayor cantidad de piezas defectuosas
