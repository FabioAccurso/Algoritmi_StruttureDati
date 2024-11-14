
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

bool is_solution(int size, int m) {
    return (size == (1 << m));
}

void print_result(const vector<int>& result) {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

bool by_one(int x, int y) {
    int z = x ^ y;
    int exp = log2(z);
    z = z - (1 << exp);
    return (z == 0);
}

void backtrack(vector<int>& result, int n, unordered_set<int>& used) {
    if (is_solution(result.size(), n)) {
        print_result(result);
        return;
    }

    if (result.size() == 0) {
        result.push_back(0);
        used.insert(0);
    }

    for (int i = 1; i < (1 << n); i++) {
        if (used.count(i) == 0 && by_one(i, result.back())) {
            result.push_back(i);
            used.insert(i);
            backtrack(result, n, used);
            result.pop_back();
            used.erase(i);
        }
    }
}

int main() {
    int n;
    cout << "Enter value for n: ";
    cin >> n;
    
    vector<int> result;
    unordered_set<int> used;
    backtrack(result, n, used);

    return 0;
}
