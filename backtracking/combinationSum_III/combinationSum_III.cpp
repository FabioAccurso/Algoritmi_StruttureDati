/*https://leetcode.com/problems/combination-sum-iii/?envType=problem-list-v2&envId=backtracking*/
/*Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
- Only numbers 1 through 9 are used.
- Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool is_solution(int sum, int n, int k, int subSize){
    return (sum == n && k == subSize);
}
bool is_safe(int i, int sum,int n, unordered_set<int>& used){
    return (sum+i <= n && used.count(i) == 0);
}

void backtrack(int k,int n, vector<vector<int>>& result, vector<int>& sub, int sum, unordered_set<int>& used, int index){
    if(is_solution(sum,n,k,sub.size())){
        result.push_back(sub);
        return;
    }
    else{
        for(int i = index; i<10;i++){
            if(is_safe(i,sum,n,used)){
                //makemove
                sum=sum+i;
                sub.push_back(i);
                used.insert(i);
                //backtrack
                backtrack(k,n,result,sub,sum,used,i);
                //unmakemove
                sum=sum-i;
                sub.pop_back();
                used.erase(i);
            }
        }
        return;
    }
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sub;
    unordered_set<int> used;
    int sum=0, min=0;

    for(int z=1;z<=k;z++){
        min=min+z;
    }

    if(n>=min){
        backtrack(k,n,result,sub,sum,used,1);
    }
    return result;      
}


int main(){
    int k=3; //quanti elementi ogni combinazione
    int n=9; //a quale somma arrivare
    
    vector<vector<int>> output = combinationSum3(k,n);

    if(output.size()>0){
        for(int i=0;i<output.size();i++){
            cout<<i+1<<") [ ";
            for(int j=0;j<output[i].size();j++){
                cout<<output[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
    else{
        cout<<"Non ci sono soluzioni";
    }

}

//37 minuti per completarlo -> Beats 100% leetcode