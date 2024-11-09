#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


int trovaDistanze(int numParenti, vector<int> numeriCivici){





}





int main(){
    ifstream inputFile("input.txt");
    if(!inputFile){
        cerr<<"Errore nell'apertura del file!"<<endl;
        return -1;
    }

    int numeroCasiTest, numParenti, risultato;
    vector<int> numeriCivici;
    inputFile >> numeroCasiTest;

    for(int i = 0; i<numeroCasiTest; i++){
        inputFile>>numParenti;
        for(int j = 0 ; j < numParenti; j++){
            inputFile>>numeriCivici[j];
        }

    }

    risultato = trovaDistanze(numParenti,numeriCivici);
    cout<<"La somma minima della distanza dalla casa dei parenti e': "<<risultato;
}