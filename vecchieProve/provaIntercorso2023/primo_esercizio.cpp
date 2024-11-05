/*Si implementi un algoritmo seguendo l’approccio Divide et Impera per contare le occorrenze di un intero K in un array non ordinato A[].*/

/* La complessita' credo sia O(n) perche vengono comunque fatti n confronti. Proprio per questo non sono sicuro al 100% della correttezza ma non ho trovato soluzioni con complessita' logaritmica*/

#include<iostream>
#include <fstream>
#include <vector>
#include<cmath>
using namespace std;

int occurrence(int k, vector<int> array, int ini,int fin){
    if(ini==fin){
        if(array[ini]==k){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(ini<fin){
            int mid = (ini+fin)/2;
            int sum1=occurrence(k,array,ini,mid);
            int sum2=occurrence(k,array,mid+1,fin);
            return sum1 + sum2;
        }
        else{
            //errore
            return 0;
        }
    }
}



int main(){
    // Apri il file in lettura
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Errore nell'aprire il file di input!" << endl;
        return 1;
    }

    int numTests;
    inputFile >> numTests;  // Legge il numero di test

    for (int i = 0; i < numTests; i++) {
        int k, arraySize;
        
        // Legge il valore di k e la dimensione dell'array
        inputFile >> k >> arraySize;

        // Legge gli elementi dell'array
        vector<int> array(arraySize);
        for (int j = 0; j < arraySize; j++) {
            inputFile >> array[j];
        }

        int result = occurrence(k,array,0,arraySize-1);
        cout<<"Nel caso di test "<<i+1<<" ci sono "<<result<<" occorrenze del numero "<<k<<endl;
    }
}
