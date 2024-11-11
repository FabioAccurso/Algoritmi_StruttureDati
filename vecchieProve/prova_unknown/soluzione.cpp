#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

bool is_solution(int sizeResult, int numSpazi){
    return (sizeResult == 1<<numSpazi);
}

void process_solution(const vector<string>& result){
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    cout<<"*END*"<<endl;
}

void backtrack(string parola, vector<string>& result,int index){
    if(result.empty()){
        result.push_back(parola);
    }
    if(is_solution(result.size(),parola.size()-1)){
        process_solution(result);
        return;
    }
    else{
        if(index>0){
            int size=result.size();
            for(int i=0;i<size;i++){
                string tmp = result[i];
                tmp.insert(index,1,' ');
                result.push_back(tmp);
            }
            backtrack(parola,result,index-1);
        }
    }
    return;
}



int main(){
    string parola;
    int casiTest,index;
    vector<string> result;

    ifstream input("input.txt");
    input>>casiTest;
    if(!input){
        cerr<<"Errore nell'apertura del file";
        return -1;
    }

    for(int i=0;i<casiTest;i++){
        cout<<"[!] Caso test "<<i+1<<": "<<endl;
        input>>parola;
        index=parola.size()-1;
        backtrack(parola,result,index);
        result.clear();
    }

}