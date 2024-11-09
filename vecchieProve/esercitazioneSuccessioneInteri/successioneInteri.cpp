#include <iostream>
#include <vector>
using namespace std;

int trovaElementoMancante(const vector<int>& arr,int sinistra, int destra, int differenza) {
    int mezzo = (sinistra + destra)/2;

    // Controlla se l'elemento successivo è quello mancante
    if (arr[mezzo + 1] - arr[mezzo] != differenza) {
        return arr[mezzo] + differenza;
    }

    // Controlla se l'elemento precedente è quello mancante
    if (mezzo > 0 && arr[mezzo] - arr[mezzo - 1] != differenza) {
        return arr[mezzo - 1] + differenza;
    }

    // Determina da che parte muoversi
    if (arr[mezzo] == arr.front() + mezzo * differenza) {
        sinistra = mezzo + 1;\
        return trovaElementoMancante(arr,sinistra,destra,differenza);
    } else {
        destra = mezzo - 1;
        return trovaElementoMancante(arr,sinistra,destra,differenza);
    }

    return -1; // Se non trova l'elemento mancante
}

int main() {

    vector<int> arr = {3,6,12,15,18,21}; // 9 elemento mancante
    
    int differenza = (arr.back() - arr.front()) / arr.size();
    
    int elementoMancante = trovaElementoMancante(arr,0,arr.size()-1,differenza);

    if (elementoMancante != -1) {
        cout << "L'elemento mancante è: " << elementoMancante <<endl;
    } else {
        cout << "Nessun elemento mancante trovato" <<endl;
    }

    return 0;
}
