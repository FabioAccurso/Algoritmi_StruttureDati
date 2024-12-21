/* https://leetcode.com/problems/pascals-triangle-ii/ */
#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> lastOne = {1};
    
    for(int i = 1; i<=rowIndex;i++){
        vector<int> tmp;
        tmp.push_back(1);
        for(int j=1 ; j<i;j++){
            tmp.push_back(lastOne[j]+lastOne[j-1]);
        }
        tmp.push_back(1);
        lastOne=tmp;
    }
    return lastOne;
}



int main(){
    // in questa variante le righe del triangolo partono dalla riga 0.
    int input=4;
    //con input = 4 -> output atteso: [1,4,6,4,1]  <- 5a riga triangolo Pascal
    vector<int> output=getRow(input);

    cout<<"[ ";
    for(int& out : output){
        cout<<out<<" ";
    }
    cout<<"] ";

}