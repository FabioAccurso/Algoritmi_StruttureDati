#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Funzione per calcolare la somma massima del sottarray che attraversa il centro
int maxCrossingSum(const vector<int>& nums, int left, int middle, int right) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;

    // Calcola la somma massima dalla metà verso sinistra
    for (int i = middle; i >= left; --i) {
        sum += nums[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;

    // Calcola la somma massima dalla metà verso destra
    for (int i = middle + 1; i <= right; ++i) {
        sum += nums[i];
        right_sum = max(right_sum, sum);
    }

    // Restituisce la somma massima che attraversa il centro
    return left_sum + right_sum;
}

// Funzione principale che applica il divide et impera
int maxSubArrayDivideEtImpera(const vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left]; // Caso base: un solo elemento
    }

    int middle = (left + right) / 2;

    // Calcola il massimo sottarray nella metà sinistra, nella metà destra, e attraverso il centro
    int max_left = maxSubArrayDivideEtImpera(nums, left, middle);
    int max_right = maxSubArrayDivideEtImpera(nums, middle + 1, right);
    int max_cross = maxCrossingSum(nums, left, middle, right);

    // Restituisce il massimo dei tre
    return max({max_left, max_right, max_cross});
}

// Funzione che avvia la ricerca del massimo sottarray
int maxSubArray(vector<int>& nums) {
    return maxSubArrayDivideEtImpera(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int soluzione = maxSubArray(nums);
    cout << "La somma degli elementi del massimo sottoarray è: " << soluzione << endl;

    return 0;
}
