/* https://leetcode.com/problems/is-subsequence/description/?envType=problem-list-v2&envId=dynamic-programming */
// Questa soluzione non utilizza la programmazione dinamica. 
// Nella stessa cartella e' proposta una soluzione alternativa che la usa ma con una complessita' peggiore.
//Complessità temporale: O(n)
//Complessità spaziale: O(1)
#include<iostream>
#include<vector>
using namespace std;

bool isSubsequence(string s, string t) {
    int indexS=0;
    
    for(int i=0;i<t.size();i++){
        if(s[indexS]==t[i]){
            indexS++;
        }    
    }
    
    if(indexS==s.size())
        return true;
    
    return false;
}



int main(){
    string s = "abc";
    string t = "ahbgdc";
    
    bool out = isSubsequence(s,t);
    cout<<out;
}