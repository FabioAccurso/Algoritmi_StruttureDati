#include<iostream>
#include<vector>
#include<fstream>
using namespace std;



vector<int> backtrack(int numLavori, vector<int>& durata, const vector<int>& penale, vector<int>& risultato, int& min, int& sum, bool& find, vector<int>& appoggio){
    if(appoggio.size()==numLavori && sum<min){
        find=true;
        min=sum;
        risultato=appoggio;
    }
    else if(!find){
        for(int i=0;i<numLavori;i++){
            if(durata[i]>0){
                int z=durata[i];
                int toAdd=0;
                durata[i]=0;
                appoggio.push_back(i);
                for(int k=0;k<numLavori;k++){
                    if(durata[k]>0){
                        toAdd=toAdd+(z*penale[k]);
                    }
                }
                sum=sum+toAdd;

                backtrack(numLavori,durata,penale,risultato,min,sum,find,appoggio);

                appoggio.pop_back();
                sum = sum-toAdd;
                durata[i]=z;
            }
        }
    }
    return risultato;
}






int main(){
    ifstream inputFile("input.txt");
    if(!inputFile){
        cerr<<"Errore nell'apertura del file!"<<endl;
        return -1;
    }

    int numeroCasiTest, numLavori ,k,sum=0,min=999999;
    vector<int> durata, penale, risultato,appoggio;
    bool find=false;
    inputFile >> numeroCasiTest;

    for(int i = 0; i<numeroCasiTest; i++){
        inputFile>>numLavori;
        for(int j = 0 ; j < numLavori; j++){
            inputFile>>k;
            durata.push_back(k);
            inputFile>>k;
            penale.push_back(k);
        }
        risultato=backtrack(numLavori,durata,penale, risultato,min,sum,find,appoggio);
        for(int z=0;z<numLavori;z++){
            cout<<risultato[z]<<" ";
        }
        cout<<endl;
        durata.clear();
        penale.clear();
    }

    
}