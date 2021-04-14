#include <iostream>
using namespace std;

int main() {
    int precio, clase;
    int precio1 = 0, precio2 = 0, precio3 = 0;
    int p1 = 0, p2 = 0, p3 = 0; /// Posicion
    int c1 = 0, c2 = 0, c3 = 0;  /// Contador de clases
    int a1 = 0, a2 = 0, a3 = 0; /// acumulador de precios
    int pr1 = 0, pr2 = 0, pr3 = 0; /// Promedio de precios
    cout << "Ingrese precio y clase del articulo:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "Articulo Nro " << i+1 << ":\n";
        cout << "Precio: "; cin >> precio;
        cout << "Clase: "; cin >> clase; cout << "\n";

        if (clase == 1) {
            c1++;
            a1 += precio;
            if (precio >= precio1) {
                precio1 = precio;
                p1 = i+1;
            }
        }   else if (clase == 2) {
                    c2++;
                    a2 += precio;
                    if (precio >= precio2) {
                        precio2 = precio;
                        p2 = i+1;
                    }
            }   else if (clase == 3) {
                        c3++;
                        a3 += precio;
                        if (precio >= precio3) {
                            precio3 = precio;
                            p3 = i+1;
                        }
                }   else if (clase <= 0 || clase > 3) {
                        cout << "\n\nClase no puede ser mayor a 3 ni menor o igual que 0\n\n"; return 0;
                    }
    }

    pr1 = a1/c1;
    pr2 = a2/c2;
    pr3 = a3/c3;
    cout << "\n\nEl numero de articulo mas caro para la clase 1: " << p1;
    cout << "\n\nEl numero de articulo mas caro para la clase 2: " << p2;
    cout << "\n\nEl numero de articulo mas caro para la clase 3: " << p3 << endl << endl;

    if (pr1 >= pr2 && pr1 >= pr3) {
        cout << "\n\nLa clase con mayor precio promedio es: CLASE 1";
    }   else if (pr2 >= pr1 && pr2 >= pr3) {
            cout << "\n\nLa clase con mayor precio promedio es: CLASE 2";
        }   else if (pr3 >= pr2 && pr3 >= pr1) {
                cout << "\n\nLa clase con mayor precio promedio es: CLASE 3";
            }

    return 0;
}
