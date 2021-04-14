#include <iostream>
using namespace std;

int main() {
    int b;
    cout << "Ingresar valor de b: ";
    cin >> b; cout << "\n\n";
    for (int a = 1; a <= b; a++) {
       cout << a << ",";
    }
    cout << "\n\n";
    return 0;
}
