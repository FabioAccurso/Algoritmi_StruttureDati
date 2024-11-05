#include "treap.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
using namespace std;

    vector<int> generaNumeriUnici(int n, int min, int max) {
    // Controlla che l'intervallo sia abbastanza grande per generare n numeri unici
    if (max - min + 1 < n) {
        throw std::invalid_argument("Intervallo troppo piccolo per generare numeri unici.");
    }

    unordered_set<int> numeriUnici;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribuzione(min, max);

    // Genera i numeri finché non si raggiunge la quantità desiderata
    while (numeriUnici.size() < n) {
        numeriUnici.insert(distribuzione(gen));
    }

    // Trasforma il set in un vettore e restituiscilo
    return vector<int>(numeriUnici.begin(), numeriUnici.end());
}

int main() {
    TREAP<char, int> T;
    int n = 10, min = 1, max = 20;
    char lettera;
    try {
        vector<int> numeriCasuali = generaNumeriUnici(n, min, max);
        for(int i =0; i<n; i++){
            lettera='A'+i;
            T.insert(lettera, numeriCasuali[i]);
            cout<<"("<<lettera<<","<<numeriCasuali[i]<<") ";
        }
        cout<<endl;
        T.inorderTreeWalk();
        
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}