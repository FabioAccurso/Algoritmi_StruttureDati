/* Problema dello zaino generico - BottomUp*/
#include<iostream>
#include<vector>
using namespace std;

int zaino(int dimZaino, vector<int>& pesi, vector<int>& valori){
    int n=pesi.size();
    vector<vector<int>> dp (n+1,vector<int>(dimZaino+1,0));

    //approccio bottom-up -> costruisco matrice
    for(int i=1;i<=n;i++){
        for(int w=0;w<=dimZaino;w++){
            if(pesi[i-1]<=w){
                //posso prenderlo e quindi valuto le due scelte
                dp[i][w]=max(valori[i-1]+dp[i-1][w-pesi[i-1]] , dp[i-1][w]);
            }
            else{
                //non posso prenderlo e quindi non ho scelta
                dp[i][w]=dp[i-1][w];
            }
        }
    }

//Stampo la matrice dp
/*
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
*/

    return dp[n][dimZaino];
}





int main(){
    int dimZaino=40;
    vector<int> pesi ={10,10,40};
    vector<int> valori={20,20,50};

    cout<<"il valore massimo che posso ottenere e': "<<zaino(dimZaino,pesi,valori)<<endl;
}