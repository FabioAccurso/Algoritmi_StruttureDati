/* Problema dello zaino generico - TopDown */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int zaino(int dimZaino, vector<int>& pesi, vector<int>& valori, vector<vector<int>>& dp, int index) {
    // Caso base
    if (index == 0 || dimZaino == 0) {
        return 0;
    }

    // Controlla se il risultato è già stato calcolato
    if (dp[index][dimZaino] != -1) {
        return dp[index][dimZaino];
    }

    // Caso 1: non includere l'oggetto
    int exclude = zaino(dimZaino, pesi, valori, dp, index - 1);

    // Caso 2: includere l'oggetto (se il peso lo permette)
    int include = 0;
    if (pesi[index - 1] <= dimZaino) {
        include = valori[index - 1] + zaino(dimZaino - pesi[index - 1], pesi, valori, dp, index - 1);
    }

    // Salva e restituisci il massimo tra includere e non includere l'oggetto
    return dp[index][dimZaino] = max(exclude, include);
}

int main() {
    int dimZaino = 40;
    vector<int> pesi = {10, 40, 10};
    vector<int> valori = {20, 50, 20};
    int n = pesi.size();

    // Inizializza la tabella di memoization con -1
    vector<vector<int>> dp(n + 1, vector<int>(dimZaino + 1, -1));

    cout << "Il valore massimo che posso ottenere e': " << zaino(dimZaino, pesi, valori, dp, n) << endl;

    return 0;
}
