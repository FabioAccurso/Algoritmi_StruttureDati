/* Find the element that appares once in sorted array -> Da GeeksForGeeks*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


int divide_et_impera(vector<int>& arr, int init, int end){
    if(init==end){
        return arr[init];
    }

    int middle = (init+end)/2;
    if(middle%2==0){
        middle++;
    }

    if(middle-1>=0 && arr[middle]==arr[middle-1]){
        //cerco a destra
        return divide_et_impera(arr,middle+1,end);
    }
    else if(middle+1<arr.size() && arr[middle]==arr[middle+1]) {
        //cerco a sinistra
        return divide_et_impera(arr,init,middle-1);
    }
    else{
        //trovato
        return arr[middle];
    }
    
}



int main(){
    ifstream input("input.txt");
    int casiTest, dimensione, risultato;
    
    input>>casiTest;

    for(int i=0;i<casiTest;i++){
        cout<<"Caso di test "<<i+1<<" :"<<endl;
        input>>dimensione;
        vector<int> arr(dimensione);

        //inserimento e stampa del vettore in cui farò ricerca
        cout<<"Array -> [ ";
        for(int j=0;j<dimensione;j++){
            input>>arr[j];
            cout<<arr[j]<<" ";
        }
        cout<<"]"<<endl;

        risultato=divide_et_impera(arr,0,arr.size()-1);
        cout<<"--Numero solitario = "<<risultato<<endl;
        arr.clear();
    }
}