#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int fibonacciTopDown(int n) {
    if (n <= 1){
        memo[n]=n;   
        return n; // Casi base
    }
    if (memo[n] != -1) return memo[n]; // Se già calcolato, restituiscilo
    memo[n] = fibonacciTopDown(n - 1) + fibonacciTopDown(n - 2); // Calcolo ricorsivo
    return memo[n];
}

int main() {
    int n;
    cout << "Inserisci n: ";
    cin >> n;
    memo.resize(n + 1, -1); // Inizializza memoization con -1
    cout << "Fibonacci(" << n << "): " <<endl;
    fibonacciTopDown(n);
    for(int i = 0;i<n;i++){
        cout<<memo[i]<<" ";
    }
    return 0;
}
