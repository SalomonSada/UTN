#include <iostream>
using namespace std;

int main() {
    int n, m, m2;
    for (int i = 1; i <=5; i++) {
        cout << i << ") Ingresar numero: ";
        cin >> n;

        if (i == 1) {
            m = n;
        }
        else if (i == 2) {
            if (n >= m) {
                m2 = m;
                m = n;
            }
            else {
                m2 = n;
            }
        }
        else {
            if (n >= m) {
                m2 = m;
                m = n;
            }
            else if (n >= m2) {
                m2 = n;
            }
        }
    }

    cout << "m: " << m << " | m2: " << m2 << endl;
    return 0;
}
