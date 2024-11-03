/*
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool is_solution(vector<int> sub, vector<int> nums){
    return sub.size()==nums.size();
}
void process_solution(vector<vector<int>>& result, vector<int> sub){
    //se ci fossero stati controlli di unicita' deli elementi da fare li avrei aggiunti qui
    result.push_back(sub);
}

void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int> sub, unordered_set<int>& used){
    if(is_solution(sub,nums)){
        process_solution(result,sub);
        return;
    }
    else{
        for(int i=0;i<nums.size();i++){
            //is_safe
            if(used.count(nums[i])==0){  //controllo se nums[i] e' gia' stato usato. Uso count e non find perche mi serve solo sapere se si o no, non la posizione
                //make_move
                sub.push_back(nums[i]);
                used.insert(nums[i]);
                //backtrack
                backtrack(nums,result,sub,used);
                //unmake_move
                sub.pop_back();
                used.erase(nums[i]);
            }
        }
    }
}



vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> output;
    vector<int> sub;
    unordered_set<int> used; //visto che i numeri sono unici, posso usare un set per rendere piu' efficiente la ricerca
    backtrack(nums, output, sub, used);

    return output;
}


int main(){
    vector<int> input={1,2,3};
    vector<vector<int>> output = permute(input);

    //stampa della soluzione
    for(int i = 0; i<output.size();i++){
        cout<<"Permutazione "<<i+1<<" -> ";
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}