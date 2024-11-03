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
    int make_move(int sum, vector<int>& candidates, bool* used, vector<int>& sub, int i){
        sum=sum+candidates[i];
        sub.push_back(candidates[i]);
        used[i]=true;
        return sum;
    }
    int unmake_move(int sum, vector<int>& candidates, bool* used, vector<int>& sub, int i){
        sum=sum-candidates[i];
        sub.pop_back();
        used[i]=false;
        return sum;
    }

    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& sub, int sum, int actual,bool* used){
        if(is_a_solution(sum,target)){
            //process solution
            process_solution(result,sub);
            return;
        }
        else{
            for(int i=0;i<candidates.size();i++){
                if(is_safe(candidates[i],sum,target) && used[i]==false && candidates[i]>= actual){
                    //Make move
                    sum = make_move(sum,candidates,used,sub,i);
                    //Backtracking
                    backtracking(candidates,target,result,sub,sum, candidates[i],used);
                    //Unmakemove
                    sum = unmake_move(sum,candidates,used,sub,i);
                }
            }
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sub;
        bool used[candidates.size()];
        for(int i=0;i<candidates.size();i++){
            used[i]=false;
        }
        int sum=0,actual=0;
        backtracking(candidates,target,result,sub,sum,actual,used);
        
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

//fallisce con 
//vector<int> candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//e
//int target = 27

//Da risolvere in nuova_RicercaPerfezione.cpp