#include <iostream>
using namespace std;

int fibonacciBottomUp(int n) {
    if (n <= 1) return n; // Casi base
    int prev2 = 0, prev1 = 1, current = 0;
    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2; // Calcola Fibonacci(i)
        prev2 = prev1;           // Aggiorna prev2
        prev1 = current;         // Aggiorna prev1
    }
    return current;
}

int main() {
    int n;
    cout << "Inserisci n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacciBottomUp(n) << endl;
    return 0;
}
