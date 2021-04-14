#include <iostream>
using namespace std;

int main() {
    int n=1, i=0, counter=0;
    int na;
    while (n!=0) {
        cin >> n;
        if (n!=0) {
            if (i>0) {
                if (n<=na) {
                    counter++;
                }
            }
            na = n;
            i++;
        }
   }
   if (counter == i-1) cout << "Todos ordenados" << endl;
    return 0;
}
