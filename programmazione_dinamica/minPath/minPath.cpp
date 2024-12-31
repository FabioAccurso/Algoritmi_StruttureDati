/* https://www.geeksforgeeks.org/min-cost-path-dp-6/ */

#include<iostream>
#include<vector>
using namespace std;

//approccio TopDown
int minPath(vector<vector<int>>& m, int r, int c,vector<vector<int>>& memo){
    //caso base
    if(r==m.size()-1 && c== m[0].size()-1)
        return m[r][c];
    //controlli 
    if(r>=m.size() || c>= m[0].size())
        return INT_MAX;
    //memoizzation -> senza questa matrice non sarebbe un approccio dp, ma solo forza bruta
    if(memo[r][c]!=-1)
        return memo[r][c];
    // caso generico
    memo[r][c] = m[r][c] + min( min(minPath(m,r+1,c,memo),minPath(m,r,c+1,memo)) , minPath(m,r+1,c+1,memo) );
    return memo[r][c];
} 




int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,8,2},{1,5,3}}; //output atteso: 8
    vector<vector<int>> memo(matrix.size() ,vector<int>(matrix[0].size(),-1));
    int out = minPath(matrix,0,0,memo);
    cout<<"[Test 1] Output: "<<out<<endl;

    vector<vector<int>> matrix_2 = {{1,2,105},{4,8,100},{2,1,1}}; //output atteso: 7
    vector<vector<int>> memo_2(matrix_2.size() ,vector<int>(matrix_2[0].size(),-1));
    out = minPath(matrix_2,0,0,memo_2);
    cout<<"[Test 2] Output: "<<out<<endl;
}