#include<iostream>
using namespace std;

int N=4;
int matrice[4][4]={1,1,0,0,1,1,1,0,1,0,1,0,1,0,1,1};
int soluzione[4][4]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


bool backtrack(int riga, int colonna){
    if(riga==N-1 && colonna==N-1 && matrice[riga][colonna]==1){
        //aggiungere 1 a soluzione
        soluzione[riga][colonna]=1;
        return true;
    }
    if(riga<N&&riga>=0&&colonna<N&&colonna>=0){
        if(matrice[riga+1][colonna]==1 && backtrack(riga+1,colonna)==true){
            soluzione[riga+1][colonna]=1;
            return true;
        }
        if(matrice[riga][colonna+1]==1 && backtrack(riga,colonna+1)==true){
            soluzione[riga][colonna+1]=1;
            return true;
        }
        else{
            soluzione[riga][colonna]=0;
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    cout<<"Matrice di partenza:"<<endl;
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<matrice[i][j];  
        }
        cout<<endl;
    }

    cout<<"\nMatrice soluzione:"<<endl;
    if(backtrack(0,0)){
        //stampa
        for(int i = 0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<soluzione[i][j];  
            }
            cout<<endl;
        }
    }
}