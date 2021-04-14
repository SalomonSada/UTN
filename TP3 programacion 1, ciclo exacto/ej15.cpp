#include <iostream>
using namespace std;

int main() {
    int num, Max = -1000, Max2;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ") Ingrese un numero: ";
        cin >> num;
        if (num >= Max) {
            Max2 = Max;
            Max = num;
        }   else if (num >= Max2) {
                Max2 = num;
            }
    }
    cout << endl << Max << endl << Max2 << endl;
    return 0;
}
