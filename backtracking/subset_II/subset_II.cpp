/*https://leetcode.com/problems/subsets-ii/description/?envType=problem-list-v2&envId=backtracking*/
/*Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool is_solution(int sizeResult, int sizeNums){
    return ( sizeResult == (1 << sizeNums) );
}

bool check_duplicates(vector<vector<int>>& result, vector<int>& tmp){
    for(int i = 0; i<result.size(); i++){
        if(result[i]==tmp){
            return true;
        }
    }
    return false;
}


void backtrack(vector<int>& nums, vector<vector<int>>& result, int& index){
    if(is_solution(result.size(),nums.size())){
        return;
    }
    else{
        if(result.size() == 0){ //aggiunge primo sotto insieme che è il sottoinsieme vuoto
            result.push_back({});
            backtrack(nums,result,index);
        }
        else if(index<nums.size()){
            int presenti=result.size(); //vado a fissare il numero di volte per cui devo eseguire il for -> ovvero quanti sottoinsiemi devo creare visti i precedenti
            for(int i = 0; i<presenti; i++){
                vector<int> tmp = result[i];
                tmp.push_back(nums[index]);
                if(check_duplicates(result, tmp)){
                    continue;
                }
                result.push_back(tmp);
            }
            index=index+1;
            backtrack(nums,result,index);
        }
        return;
    }
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    int index=0;
    sort(nums.begin(), nums.end());
    backtrack(nums,result, index);

    return result;
}


int main(){
    vector<int> nums={4,4,4,1,4};
    vector<vector<int>> output = subsets(nums);

    //stampa output qui
    for(int i = 0; i<output.size(); i++){
        cout<<i+1<<") -> [ ";
        for(int j = 0; j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<"]"<< endl;
    }
}