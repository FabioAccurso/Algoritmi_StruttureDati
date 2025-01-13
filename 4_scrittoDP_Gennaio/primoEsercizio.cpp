#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int costoMinimoTaglio(int L, vector<int>& tagli) {
    // Aggiungere gli estremi della trave
    tagli.insert(tagli.begin(), 0);
    tagli.push_back(L);
    
    int n = tagli.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Riempire la tabella dp
    for (int lun = 2; lun < n; ++lun) { // Lunghezza dell'intervallo
        for (int i = 0; i < n - lun; ++i) {
            int j = i + lun;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) { // Provare tutti i tagli intermedi
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + tagli[j] - tagli[i]);
            }
        }
    }

    
    return dp[0][n - 1];
}

int main() {
    // Esempi di input
    vector<int> cuts1 = {2, 20, 25};
    vector<int> cuts2 = {4, 5, 7, 8};
    vector<int> cuts3 = {25, 50, 75};

    cout << "Costo_minimo = " << costoMinimoTaglio(30, cuts1) << endl;  //minimo atteso 60
    cout << "Costo_minimo = " << costoMinimoTaglio(10, cuts2) << endl;  //minimo atteso 22
    cout << "Costo_minimo = " << costoMinimoTaglio(100, cuts3) << endl;  //minimo atteso 200

    return 0;
}
