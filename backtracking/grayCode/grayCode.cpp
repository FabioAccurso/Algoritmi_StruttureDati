#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;

//nel programma usero' [1<<n] dove n e' un intero. Questa scrittura genera un numero il quale nella sua rappresentazione binaria \
//ha un 1 alla posizione n a partire da destra verso sinistra

bool is_solution(int tmpSize, int n){
    return (tmpSize == 1 << n);
}

bool differ_by_1(int x, int y){
    // ^ -> xor , ovvero per ogni bit differente nella rappresentazione binaria mette 1, per ogni bit uguale 0
    int k = x^y;
    //se k ha un solo bit alto (1) allora x e y differiscono di un solo bit!

    //calcolo la posizione dell 1 piu' a sinistra del numero k attraverso il logaritmo in base 2
    int esponente=floor(log2(k));
    //sottraggo 2^(posizione dell'1 piu' a sinistra) a k
    k = k - (1 << esponente);
    //se k e' diventato 0 allora c'era soltanto quell 1 nella rappresentazione binaria. Quindi x e y differivano solo di 1 bit
    if(k==0){
        return true;
    }
    return false;
}



void backtrack(vector<int>& result, int n, unordered_set<int>& used, vector<int>& tmp,bool& find){
    if(tmp.size()==0){
        //se e' la prima volta che eseguo il backtrack so' per certo che il primo elemento del vettore soluzione dovra' essere 0 e quindi posso inserirlo
        tmp.push_back(0);
    }
    
    if(is_solution(tmp.size(),n) && find==false && differ_by_1(tmp.front(),tmp.back())){
        result=tmp;
        find=true;
        return;
    }
    else if(find==false){
        //parto da 1 perche 0 l'ho gia' sicuramente inserito
        for(int i=1; i < (1<<n); i++){
            if(used.count(i)==0 && differ_by_1(i,tmp.back())){
                tmp.push_back(i);
                used.insert(i);
                backtrack(result,n,used,tmp,find);
                used.erase(i);
                tmp.pop_back();
            }
        }
       
    }
    return;
}






vector<int> grayCode(int n) {
    vector<int> result;
    unordered_set<int> used;
    vector<int> tmp;
    bool find=false;
    backtrack(result,n,used,tmp,find);

    return result;
}




int main(){
    int n=2;
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