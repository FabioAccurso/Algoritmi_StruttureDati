#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//funzione per trovare la sequenza di numeri primi tra p ed s
vector<int> findPrimi(int p,int s){
    vector<int> vect;
    for(int i=p+1;i<=s;i++){
        if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 && i%11!=0){
            vect.push_back(i);
        }
        else if(i==2 || i==3 || i==5 || i==7 || i==11){
            vect.push_back(i);
        }
    }
    return vect;
}


void backtrack(vector<vector<int>>& result, int s, int n, int index, vector<int>& primiPoss,vector<int>& subset,int& sum){
    if(subset.size()==n && sum==s){
        result.push_back(subset);
        return;
    }
    else if(subset.size()<n){
        for(int i=index;i<primiPoss.size();i++){
            if(sum+primiPoss[i]<=s){
                sum += primiPoss[i];
                subset.push_back(primiPoss[i]);
                backtrack(result,s,n,i+1,primiPoss,subset,sum);
                subset.pop_back();
                sum -= primiPoss[i];
            }
        }
    }
    return;
}



int main(){
    int numCasi,s,p,n,sum=0;
    vector<int> primiPoss,subset;
    vector<vector<int>> result;
    ifstream input("input_secondoEs.txt");
    if(!input){
        cerr<<"Errore nell'apertura del file di input";
        return -1;
    }
    
    input>>numCasi;

    for(int i = 0; i<numCasi;i++){
        cout<<"[!] Caso di test "<<i+1<<":"<<endl;
        input>>s;
        input>>n;
        input>>p;

        primiPoss=findPrimi(p,s);
        backtrack(result,s,n,0,primiPoss,subset,sum);

        //stampa del risultato
        for(int j=0;j<result.size();j++){
            cout<<"[ ";
            for(int k=0;k<result[j].size();k++){
                cout<<result[j][k]<<" ";
            }
            cout<<"]"<<endl;
        }

        //pulizia variabili usate
        result.clear();
        subset.clear();
        sum=0;
        primiPoss.clear();
    }

}



//risolto in 38 minuti