#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArraySum(vector<int> arr) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() {
    vector<int> arr1 = {-1, -3, 4, 2};
    vector<int> arr2 = {-1, 2, -5, 7};

    cout << maxSubArraySum(arr1) << endl;  // Output: 6
    cout << maxSubArraySum(arr2) << endl;  // Output: 7

    // Additional test cases
    vector<int> arr3 = {1, -2, 3, 5, -3, 2};
    vector<int> arr4 = {0, -1, 2, -1, 3};

    cout << maxSubArraySum(arr3) << endl;  // Output: 8
    cout << maxSubArraySum(arr4) << endl;  // Output: 4

    return 0;
}
