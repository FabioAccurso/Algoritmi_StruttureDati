/* Soluzione di GPT */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void solveFerryProblem(int n, int t, int m, vector<int>& arrivalTimes) {
    // Array DP per memorizzare il tempo minimo richiesto e il numero di viaggi
    // dp[i] rappresenta il tempo minimo per trasportare le prime i auto
    // trips[i] rappresenta il numero di viaggi necessari per trasportare le prime i auto
    vector<int> dp(m + 1, INT_MAX);
    vector<int> trips(m + 1, 0);
    dp[0] = 0; // Nessuna auto, nessun tempo richiesto

    // Ciclo per calcolare il tempo minimo per ogni numero di auto da trasportare (fino a m)
    for (int i = 1; i <= m; ++i) {
        // Considera ogni possibile batch di auto che il traghetto può caricare (fino a n auto)
        for (int j = 1; j <= min(i, n); ++j) {
            int lastBatch = i - j; // Numero di auto rimaste da trasportare prima di questo batch
            // Calcola il tempo per trasportare questo batch
            // Il tempo è il massimo tra l'arrivo dell'ultima auto di questo batch e il tempo necessario
            // per tornare dal batch precedente, più il tempo per attraversare e tornare (2 * t)
            int timeForBatch = max(arrivalTimes[i - 1], dp[lastBatch]) + 2 * t;

            // Aggiorna il tempo minimo per trasportare le prime i auto
            if (timeForBatch < dp[i]) {
                dp[i] = timeForBatch;
                trips[i] = trips[lastBatch] + 1; // Incrementa il conteggio dei viaggi
            }
        }
    }

    // Risultato finale: tempo totale e numero di viaggi necessari
    // Nota: sottraiamo t dal tempo finale perché il traghetto non deve tornare dopo l'ultimo viaggio
    cout << dp[m] - t << " " << trips[m] << endl;
}

int main() {
    // Inizializza i parametri del problema
    int n = 2, t = 10, m = 10;
    // Tempi di arrivo delle auto al terminale
    vector<int> arrivalTimes = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

    // Risolvi il problema per i dati di input
    solveFerryProblem(n, t, m, arrivalTimes);

    return 0;
}
