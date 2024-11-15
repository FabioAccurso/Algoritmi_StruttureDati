// Problema 1 Intercorso
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


int massimoLocale(vector<int>& array, int start, int end) {
    if (start == end) {
        return array[start];
    }
    int mid = (start + end) / 2;
    if ((mid == 0 || array[mid] >= array[mid - 1]) && (mid == array.size() - 1 || array[mid] >= array[mid + 1])){
        return array[mid];
    }
    if (mid > 0 && array[mid - 1] > array[mid]) {
        return massimoLocale(array, start, mid - 1);
    }
    return massimoLocale(array, mid + 1, end);
}


int main(){
    ifstream input("input_probl_1.txt");
    int casiTest,dimensione,risultato;;

    input>>casiTest;

    for(int i=0;i<casiTest;i++){
        input>>dimensione;
        vector<int> array(dimensione);

        cout<<"Test "<<i+1<<" -> Array = [ ";
        for(int j=0;j<dimensione;j++){
            input>>array[j];
            cout<<array[j]<<" ";
        }
        cout<<"]"<<endl;

        risultato=massimoLocale(array,0,dimensione-1);

        cout<<"Un massimo locale e' ("<<risultato<<")"<<endl;
    }

}