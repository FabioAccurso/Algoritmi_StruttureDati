/* https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/ */
#include<iostream>
#include<vector>
using namespace std;

//approccio bottom-up
int maxRobb(vector<int>& hval){
    int n = hval.size();
    vector<int> dp(n,0);
    //casi base
    dp[n-1]=hval[n-1];
    dp[n-2]=max(hval[n-2] , hval[n-1]);

    for(int i=n-3; i>=0; i--){
        dp[i]=max(hval[i]+dp[i+2],dp[i+1]);
    }

    //stampa vettore massimi relativi
    /*
    for(int k : dp)
        cout<<k<<" ";
    */
   return dp[0];
}

int main(){
    vector<int> hval={6,7,1,3,8,2,4};
    int out;
    out = maxRobb(hval);
    cout<<"[Test 1] output: "<<out<<endl;

    vector<int> hval_2 ={5,3,4,11,2};
    out = maxRobb(hval_2);
    cout<<"[Test 2] output: "<<out<<endl;
}