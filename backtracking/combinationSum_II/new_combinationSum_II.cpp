/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool is_a_solution(int sum, int target) {
    return sum == target;
}

bool is_safe(int candi, int sum, int target) {
    return sum + candi <= target;
}

void process_solution(unordered_set<string>& seen, vector<vector<int>>& result, vector<int>& sub) {
    string key;
    for (int num : sub) {
        key += to_string(num) + ",";
    }
    if (seen.find(key) == seen.end()) { //ovvero vuol dire che non lo ha trovato se restituisce seen.end()
        result.push_back(sub);
        seen.insert(key);
    }
}

int make_move(int sum, vector<int>& candidates, vector<bool>& used, vector<int>& sub, int i) {
    sum += candidates[i];
    sub.push_back(candidates[i]);
    used[i] = true;
    return sum;
}

int unmake_move(int sum, vector<int>& candidates, vector<bool>& used, vector<int>& sub, int i) {
    sum -= candidates[i];
    sub.pop_back();
    used[i] = false;
    return sum;
}

void backtracking(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& sub, int sum, int actual, vector<bool>& used, unordered_set<string>& seen) {
    if (is_a_solution(sum, target)) {
        process_solution(seen, result, sub);
        return;
    }

    for (int i = actual; i < candidates.size(); i++) {
        if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) continue;
        if (is_safe(candidates[i], sum, target) && !used[i]) {
            sum = make_move(sum, candidates, used, sub, i);
            backtracking(candidates, target, result, sub, sum, i + 1, used, seen);
            sum = unmake_move(sum, candidates, used, sub, i);
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); //ordino i candidati in modo da rendere piu semplice l'accesso e da poter escludere un intero ramo se un elemento fa eccedere la somma-> anche i successivi lo faranno sicuramenente
    vector<vector<int>> result;
    vector<int> sub;
    vector<bool> used(candidates.size(), false);
    unordered_set<string> seen;

    backtracking(candidates, target, result, sub, 0, 0, used, seen);
    return result;
}

int main() {
    vector<int> candidates = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int target = 27;
    vector<vector<int>> result = combinationSum2(candidates, target);

    if (result.empty()) {
        cout << "Non ci sono soluzioni" << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << i + 1 << "a combinazione possibile -> ";
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
