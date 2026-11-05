#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n == 0) {
        cout << "Fibonacci number is: 0" << endl;
        return 0;
    }
    if (n == 1) {
        cout << "Fibonacci number is: 1" << endl;
        return 0;
    }

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    cout << "Fibonacci number is: " << c << endl;

    return 0;
}