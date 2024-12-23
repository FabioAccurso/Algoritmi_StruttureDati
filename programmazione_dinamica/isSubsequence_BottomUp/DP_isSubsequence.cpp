/* https://leetcode.com/problems/is-subsequence/description/?envType=problem-list-v2&envId=dynamic-programming */

//SOLUZIONE NON MIA.
	//Questa soluzione è stata proposta da chatgpt in quanto in la mia soluzione non utilizzava la DP.
	//Ritengo però che la mia soluzione pur non usando la DP (a differenza di questa soluzione qui) sia computazionalmente migliore 
	//in quanto ha complessità temporale O(n) e spaziale O(1), a differenza di questa soluzione che invece ha:
//Complessità Temporale: O(n*m)
//Complessità Spaziale: O(n*m)
#include<iostream>
#include<vector>
using namespace std;

bool isSubsequence(string s, string t) {
    int sizeS=s.size(),sizeT=t.size();
    vector<vector<bool>> dp(sizeS+1, vector<bool>(sizeT+1, false));
    
    //caso base -> stringa vuota "" è sicuramente sottostringa di qualunque stringa
    for(int i=0;i<=sizeT;i++){
        dp[0][i]=true;
    }
    
    for(int i = 1;i<=sizeS;i++){
        for(int j=1;j<=sizeT;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[sizeS][sizeT];
}

int main(){
    string s = "abc";
    string t = "ahbgdc";
    
    bool out = isSubsequence(s,t);
    if(out==true)
        cout<<"True";
    else
        cout<<"False";
}