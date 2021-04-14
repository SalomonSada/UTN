#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Ingresar valor de A: ";
    cin >> a;
    cout << "\nIngresar valor de B: ";
    cin >> b; cout << "\n\n";

    if (a <= b) {
        cout << "De 'A' hasta 'B': ";
        for (a, b; a <= b; a++) {
            cout << a << ",";
        }
    }
    else {
        cout << "De 'B' hasta 'A': ";
        for (a, b; b<= a; b++) {
            cout << b << ",";
        }
    }
    cout << endl;
    return 0;
}
