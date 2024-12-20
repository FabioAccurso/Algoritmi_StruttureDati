#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int j = 1; j <= n; j++) {
        dp[j] = max(dp[j - 1] + arr[j - 1], arr[j - 1]);
    }

    int maxSum = dp[1];

    for (int j = 2; j <= n; j++) {
        maxSum = max(maxSum, dp[j]);
    }

    return maxSum;
}

int main() {
    //Test case 1: Fornito da traccia
    vector<int> arr = {-1,-1,4,2};  //output atteso: 6
    cout << "[1] Maximum subarray sum is " << maxSubArray(arr) << endl;

    //Test case 2: Fornito da traccia
    arr = {-1,2,-5,7}; //output atteso: 7
    cout << "[2] Maximum subarray sum is " << maxSubArray(arr) << endl;

    //Test case 3: Array con numeri sia positivi che negativi. Sottoarray con somma maggiore -> [2,7,-2,3]
    arr = {1, 2, -3, -4, 2, 7, -2, 3}; //output atteso: 10
    cout << "[3] Maximum subarray sum is " << maxSubArray(arr) << endl;

    //Test case 4: Tutti numeri positivi. Il Sottoarray con la somma maggiore corrisponde all'array di partenza
    arr = {4, 2, 7, 2, 3}; //output atteso: 18
    cout << "[4] Maximum subarray sum is " << maxSubArray(arr) << endl;
    
    //Test case 5: Tutti numeri negativi. Il sottoarray con la somma maggiore e' composto dal solo numero maggiore, il piu' grande tra i negativi.
    arr = {-4, -2, -7, -5, -3}; //output atteso: -2
    cout << "[5] Maximum subarray sum is " << maxSubArray(arr) << endl;
    
    //Test case 6: Tutti numeri negativi ed uno zero. Il sottoarray con somma maggiore corrisponde proprio allo zero.
    arr = {-4, -2, 0, -2, -3}; //output atteso: 0
    cout << "[6] Maximum subarray sum is " << maxSubArray(arr) << endl;
    
    return 0;
}
