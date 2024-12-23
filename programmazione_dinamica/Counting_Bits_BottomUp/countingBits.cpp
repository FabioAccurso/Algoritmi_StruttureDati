/* https://leetcode.com/problems/counting-bits/?envType=problem-list-v2&envId=dynamic-programming */

#include<iostream>
#include<vector>
using namespace std;

//15-> [0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4]

//0 -> 0 pari (caso base)
//1 ->  1 dispari (precedente+1)
//2 -> 1 pari (1 elemento fa)
//3 -> 2 dispari (precedente+1)
//4 -> 1 pari (2 elementi fa)
//5 -> 2 dispari (precedente+1)
//6 -> 2 pari (3 elementi fa)
//7 -> 3 dispari (precedente+1)
//8 -> 1 pari (4 elementi fa)
//9 -> 2 dispari    {etc}
//10 -> 2 pari
//11 -> 3 dispari
//12 -> 2 pari
//13 -> 3 dispari
//14 -> 3 pari
//15 -> 4 dispari


//approccio Bottom Up
vector<int> countBits(int n) {
    vector<int> dp={0};
    int k=1;
    
    for(int i=1 ; i<=n;i++){    //O(n)
        
        //O(1)
        if(i%2==0){ //pari
            dp.push_back(dp[i-k]);   
            k++;
        }
        //O(1)
        else{ //dispari -> precedente + 1
            dp.push_back(dp[i-1]+1);
        }
    }
    return dp;
}



int main(){
    int input=5;
    vector<int> output = countBits(input);
    
    cout<<"[ ";
    for(int n : output){
        cout<<n<<" ";
    }
    cout<<"]"<<endl;
    
    
}