/* https://leetcode.com/problems/pascals-triangle/ */
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> risultato;
    risultato.push_back({1});
    
    for(int i = 1;i<numRows;i++){
        vector<int> tmp;
        tmp.push_back(1);

        for(int j=1;j<=risultato.back().size()-1;j++){
            tmp.push_back(risultato.back()[j]+risultato.back()[j-1]);   
        }
        tmp.push_back(1);

        risultato.push_back(tmp);
    }

    return risultato;
}

int main(){
    int input=5;
    //con input =5 -> output atteso: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]  <- 5a riga triangolo Pascal
    vector<vector<int>> output=generate(input);

    //provo il for range-based per capirne il funzionamento. Posso farlo in quanto non mi occorrono informazioni su indici.
    cout<<"[ ";
    for(vector<int>& vec : output){
        cout<<"[ ";
        for(int& out : vec){
            cout<<out<<" ";
        }
        cout<<"] ";
    }
    cout<<"] ";

}