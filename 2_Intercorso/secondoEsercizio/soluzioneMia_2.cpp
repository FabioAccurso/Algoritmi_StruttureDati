// Problema 2 Intercorso -> Non corretta al 100%
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

// Problema 2
void minPath(vector<vector<int>>& matrix, int m, int n, int row, int col, int cost, int& minCost, vector<int>& percorso, vector<int>& tmp) {
    if (col == n - 1) { // soluzione
        minCost = min(cost, minCost);
        if (minCost == cost) {
            percorso = tmp;
        }
        return;
    }

    else{
        for (int i = -1; i < 2; i++) { // possibili mosse su riga
            row = row + i; // [!!!!] errore grave!!! Dovevo usare (int newRow=row+i) 
            if (row < 0) {
                tmp.push_back(m);
                cost = cost + matrix[m - 1][col + 1];
                minPath(matrix, m, n, m - 1, col + 1, cost, minCost, percorso, tmp);
                cost = cost - matrix[m - 1][col + 1];
                tmp.pop_back();
            }
            else if (row > m - 1) {
                tmp.push_back(1);
                cost = cost + matrix[0][col + 1];
                minPath(matrix, m, n, 0, col + 1, cost, minCost, percorso, tmp);
                cost = cost - matrix[0][col + 1];
                tmp.pop_back();
            }
            else {
                tmp.push_back(row + 1);
                cost = cost + matrix[row][col + 1];
                minPath(matrix, m, n, row, col + 1, cost, minCost, percorso, tmp);
                cost = cost - matrix[row][col + 1];
                tmp.pop_back();
            }
        }
    }
    return;
}


int main(){
    ifstream input("input_probl_2.txt");
    vector<int> percorso,tmp;
    int minCosto=INT_MAX;
    int m,n, casiTest;

    input >> casiTest;

    for(int i=0;i<casiTest;i++){
        input>>m;
        input>>n;
        vector<vector<int>> matrix(m,vector<int>(n));

        cout<<"[Test "<<i+1<<"]"<<endl<<"Matrice di partenza:"<<endl;
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                input>>matrix[j][k];
                cout<<matrix[j][k]<<" ";
            }
            cout<<endl;
        }
        
        //chiamo la funzione di backTracking facendola partire una volta da ogni elemento della prima colonna
        for(int j=0;j<m;j++){
            //[!]Le due operazioni su tmp non le ho aggiunte sulla copia consegnata all esame (anche se ho solo dato un idea del main)
            tmp.clear();
            tmp.push_back(j+1);
            minPath(matrix,m,n,j,0,matrix[j][0],minCosto,percorso,tmp);
        }

        cout<<"Percorso -> [ ";
        for(int j=0;j<percorso.size();j++){
            cout<<percorso[j]<<" ";
        }
        cout<<"]"<<endl;
        cout<<"Costo -> ("<<minCosto<<")"<<endl;


        percorso.clear();
        minCosto=INT_MAX;
    }



}