#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//la posizione ottima corrisponde alla mediana, ovvero l'elemento centrale o la media degli elementi centrali
int trovaDistanze(int numParenti, vector<int>& numeriCivici){

    int mediana=(numeriCivici.size())/2;
    int posizioneOttima,somma=0;
    if(numeriCivici.size()%2==0){
        //devo fare media dei centrali
        posizioneOttima=(numeriCivici[mediana]+numeriCivici[mediana-1])/2;
    }
    else{
        //devo prendere elemento centrale   
        posizioneOttima=numeriCivici[mediana];    
    }

    for(int i=0;i<numParenti;i++){
        somma=somma + abs(posizioneOttima-numeriCivici[i]);
    }

    return somma;

}





int main(){
    ifstream inputFile("input.txt");
    if(!inputFile){
        cerr<<"Errore nell'apertura del file!"<<endl;
        return -1;
    }

    int numeroCasiTest, numParenti, risultato,k;
    vector<int> numeriCivici;
    inputFile >> numeroCasiTest;

    for(int i = 0; i<numeroCasiTest; i++){
        inputFile>>numParenti;
        for(int j = 0 ; j < numParenti; j++){
            inputFile>>k;
            numeriCivici.push_back(k);
        }
        risultato = trovaDistanze(numParenti,numeriCivici);
        cout<<"La somma minima della distanza dalla casa dei parenti e': "<<risultato<<endl;
        numeriCivici.clear();
    }

    
}