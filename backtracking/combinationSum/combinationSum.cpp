/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
*/

#include<iostream>
#include<vector>
using namespace std;

bool is_a_solution(int sum, int target){
    if(sum==target)
        return true;
    else
        return false;
}

bool is_safe(int sum, int candidato, int target){
    if(sum+candidato<=target)
        return true;
    else
        return false;
}

void make_move(vector<int>& subresult, int candidato, vector<vector<int>>& risultato){
   subresult.push_back(candidato);
}


void unmake_move(vector<int>& subresult){
    subresult.pop_back();
}


void backtrack(vector<int>& candidates, vector<vector<int>>& risultato, int target, int sum, vector<int>& subresult, int attuale){
    if(is_a_solution(sum,target)){
        risultato.push_back(subresult);
        return;
    }
    else{
        for(int i=0;i<candidates.size();i++){
            if(is_safe(sum,candidates[i],target) && candidates[i]>=attuale){
                sum=sum+candidates[i];  //makemove
                make_move(subresult,candidates[i],risultato);
                backtrack(candidates,risultato,target,sum,subresult,candidates[i]);
                sum=sum-candidates[i];  //unmake_move();
                unmake_move(subresult);
            }
        }
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> risultato;
    int sum=0,attuale=0;
    vector<int> subresult;
    backtrack(candidates,risultato,target,sum,subresult,attuale);

    return risultato;

}

int main(){
    vector<int> input = {2,3,5};
    int target = 8;

    vector<vector<int>> soluzione= combinationSum(input,target);
    //output atteso [[2,2,2,2],[2,3,3],[3,5]]
    if(soluzione.size()==0){
        cout<<"Non ci sono soluzioni";
    }
    else{
        for(int i=0;i<soluzione.size();i++){
            cout<<i+1<<"a combinazione possibile -> ";
            for(int j=0;j<soluzione[i].size();j++){
                cout<<soluzione[i][j]<<" ";
            }
            cout<<endl;
        }
    }   
}