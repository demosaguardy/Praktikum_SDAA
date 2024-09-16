#include <iostream>
using namespace std;


long faktorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * faktorial(n - 1); 
    }
}

int main() {
    int a;

    cout << "Masukkan nilai: ";
    cin >> a;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - i - 1; j++) {
            cout << " ";
        }

        for (int j = 0; j <= i; j++) {
            cout << faktorial(i) / (faktorial(j) * faktorial(i - j)) << " ";
        }

        cout << endl;
    }

    return 0;
}
