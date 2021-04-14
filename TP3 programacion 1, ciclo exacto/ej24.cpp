#include <iostream>
using namespace std;

int main() {
    int sueldo, sueldoM, antiguedad, antiguedadM, posicion; /// Posicion => numero de empleado && M => de la persona con mayor sueldo.
    int acumulador = 0, contador = 0, promedio; /// Acumulador de antigüedad && contador de personas que ganen mas de 20k && promedio de antigüedad.

    for (int i = 1; i <= 30; i++) {
        cout << "Empleado Nro " << i << ":\n";
        cout << "Sueldo: "; cin >> sueldo;
        cout << "Antiguedad: "; cin >> antiguedad; cout << "\n";

        if (sueldo >= sueldoM)  {
            sueldoM = sueldo;
            posicion = i;
            antiguedadM = antiguedad;
        }
        if (sueldo > 20000) {
            acumulador += antiguedad;
            contador++;
        }
    }
    promedio = acumulador/contador;
    /// Respuestas:
    cout << "\nEl numero de empleado con mayor sueldo es: " << posicion << " | gana: " << sueldoM << " | y su antiguedad es: " << antiguedadM;
    cout << "\n\nEl promedio de antiguedad de los empleados que ganan mas de 20.000: " << promedio << endl;
    return 0;
}
/// ¿Que hay que hacer?
/// -. Posicion y antiguedad del empleado con mayor sueldo.
/// -. Promedio de antiguedad de empleados que ganan ms de 20k.
