#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int minCoins(vector<int>& coins, int V) {
    int maxValue = V + coins[0]; // Massimo valore da considerare
    vector<int> dp(maxValue + 1, INT_MAX); // Array dp per memorizzare il minimo numero di monete per valori da 1 a maxValue

    dp[0] = 0; // Caso base: 0 monete per valore 0

    // Costruisce il vettore dp, ovvero calcola per ogni valore da 1 a maxValue il numero minimo di monete richieste
    for (int i = 1; i <= maxValue; i++) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Cerca il valore più piccolo maggiore o uguale a V che abbia una soluzione, ovvero un numero di monete ben definito per raggiungerlo
    for (int i = V; i <= maxValue; i++) {
        if (dp[i] != INT_MAX) {
            return dp[i];
        }
    }

    return -1; // Nel caso non sia possibile raggiungere il valore o i suoi successivi
}

int main() {
    //Test case 1
    int V=10;
    vector<int> coins = {1,5};
    int result = minCoins(coins, V); //output atteso: 2
    cout << "Il numero minimo di monete necessarie e': " << result << endl;

    //Test case 2
    V=7;
    coins = {1, 3, 4, 5};
    result = minCoins(coins, V); //output atteso: 2
    cout << "Il numero minimo di monete necessarie e': " << result << endl;

    //Test case 3
    V=11;
    coins = {2, 3, 5};
    result = minCoins(coins, V); //output atteso: 3
    cout << "Il numero minimo di monete necessarie e': " << result << endl;

    //Test case 4
    V=1;
    coins = {3, 5};
    result = minCoins(coins, V); //output atteso: 1
    cout << "Il numero minimo di monete necessarie e': " << result << endl;


    //Test case 5
    V=7;
    coins = {3, 5};
    result = minCoins(coins, V); //output atteso: 2
    cout << "Il numero minimo di monete necessarie e': " << result << endl;



    //Test case 6
    V=100;
    coins = {2, 5, 10};
    result = minCoins(coins, V); //output atteso: 10
    cout << "Il numero minimo di monete necessarie e': " << result << endl;
    
    return 0;
}
