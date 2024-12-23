#include<iostream>
#include<vector>
using namespace std;

// {!} Esercizio da completare
// n=3 -> ((()))   (()())  ()(())  (())()  ()()()
// n=2 -> (())  ()()
// n=1 -> ()

vector<string> generateParenthesis(int n) {
    vector<string> dp;

    //caso base
    for(int i=1;i<1;i++){
        dp.push_back("");
        for(int j=1;j<=(2*n);j++){
            dp[i].push_back('(');
            //CONTINUA
        }
    }   
    return dp;
}



int main(){
    int input=3;
    vector<string> output = generateParenthesis(input);
    
    cout<<"[ '";
    for(string k : output){
        cout<<k<<" , ";
    }
    cout<<"' ]";
}