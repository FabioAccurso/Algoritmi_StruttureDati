/*Si implementi un algoritmo che riceve un intero i compreso tra 1 e 10 e stampa l’i-esima riga del
triangolo di Tartaglia. L’input 0 termina i casi di test*/

#include <iostream>
#include <vector>
using namespace std;

// Funzione per calcolare ricorsivamente il coefficiente binomiale usando divide et impera
int coefficienteBinomiale(int n, int k) {
    // Condizione di base
    if (k == 0 || k == n) return 1;
    // Divide et impera: somma dei coefficienti per ottenere il valore attuale
    return coefficienteBinomiale(n - 1, k - 1) + coefficienteBinomiale(n - 1, k);
}

// Funzione per generare e stampare la riga del triangolo di Tartaglia
void triangoloTartaglia(int row) {
    for (int i = 0; i <= row; i++) {
        cout << coefficienteBinomiale(row, i) << " ";
    }
    cout << endl;
}

int main() {
    int testCase, row;

    cout << "Inserisci il numero di casi di test: ";
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        do{
            cout << "Inserisci il numero di riga, tra 0 e 10, di cui calcolare triangolo di tartaglia: ";
            cin >> row;
        }while(row<0||row>10);
        

        cout << "Caso di test " << i + 1 << ", con riga = " << row << " :" << endl;
        triangoloTartaglia(row);
    }

    return 0;
}
