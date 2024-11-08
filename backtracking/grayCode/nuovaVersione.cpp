#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;

//Questa versione non e' stata fatta da me. La mia personale versione e' nel file grayCode.cpp, la quale pero' fallisce per n grande, come n=10.
//Questa versione e' utilizza una funzione di backtrack presa da una delle soluzioni piu' comprensibili 
//che ho trovato su leetcode e ho scelto di riportarla in modo da tenere traccia di questa soluzione efficiente.


bool backtrack(vector<int>& result,int n,int& num,unordered_set<int>& visited){
    if (result.size() == pow(2, n)) return true;
    for (int i = 0; i < n; i++) {
        int next = num ^ (1 << i); //questa operazione utilizza la XOR per cambiare un bit per volta in posizione i. Se questo genera un numero gia' visitato ne verra' generato un altro grazie al for

        if (visited.find(next) == visited.end()) {//questa condizione equivale a if(visited.count(next))==0)
            result.push_back(next);
            visited.insert(next);

            if (backtrack(result,n,next,visited)) return true; //se torna vero allora rompo il backtrack e ritorno vero, altrimenti elimino mossa e continuo il for

            result.pop_back();
            visited.erase(next);
        }
    }
    return false;
}

vector<int> grayCode(int n) {
    vector<int> result={0};
    unordered_set<int> used={0};
    int num=0;
    backtrack(result,n,num,used);
    
    return result;
}


int main(){
    int n=4;
    vector<int> output = grayCode(n);
    if(output.size()>0){
        cout<<"[";
        for(int i : output){
            cout<<i<<" ";
        }
        cout<<"]";
    }
    else{
        cout<<"Non ci sono soluzioni valide";
    }

}