/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.*/

#include<iostream>
#include<vector>
using namespace std;

    bool is_a_solution(int sum,int target){
        if(sum==target)
            return true;
        else
            return false;
    }
    bool is_safe(int candi, int sum, int target){
        if(sum+candi<=target)
            return true;
        else    
            return false;
    }
    void process_solution(vector<vector<int>>& result, vector<int>& sub){
        bool find=false;
            for(int k=0;k<result.size();k++){
                if(result[k]==sub)
                    find=true;
            }
            if(find==false)
                result.push_back(sub);
    }
    int make_move(int sum, vector<int>& candidates, vector<int>& sub, int i){
        sum=sum+candidates[i];
        sub.push_back(candidates[i]);
        candidates.erase(candidates.begin() + i);
        return sum;
    }
    int unmake_move(int sum, vector<int>& candidates, vector<int>& sub, int i,int candidatoBackup){
        sum=sum-candidates[i];
        sub.pop_back();
        candidates.insert(candidates.begin() + i, candidatoBackup);
        return sum;
    }

    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& sub, int sum, int actual){
        if(is_a_solution(sum,target)){
            //process solution
            process_solution(result,sub);
            return;
        }
        else{
            for(int i=0;i<candidates.size();i++){
                if(is_safe(candidates[i],sum,target) && candidates[i]>= actual){
                    int candidatoBackup=candidates[i];
                    //Make move
                    sum = make_move(sum,candidates,sub,i);
                    //Backtracking
                    backtracking(candidates,target,result,sub,sum, candidates[i]);
                    //Unmakemove
                    sum = unmake_move(sum,candidates,sub,i,candidatoBackup);
                    i--;
                }
            }
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sub;
        int sum=0,actual=0;
        backtracking(candidates,target,result,sub,sum,actual);
        
        return result;
    }


int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = combinationSum2(candidates,target);
    //output atteso {[1,1,6],[1,2,5],[1,7],[2,6]}
    if(result.size()==0){
        cout<<"Non ci sono soluzioni";
    }
    else{
        for(int i=0;i<result.size();i++){
            cout<<i+1<<"a combinazione possibile -> ";
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
}