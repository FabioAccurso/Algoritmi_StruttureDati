#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct Fit{
    string taller="X";
    string shorter="X";
};

///SOLUZIONE NON COMPLETA!!
Fit findFit(const vector<int>& lady, int height,int init, int end){
    int mid=(init+end)/2;
    if(mid+1<lady.size() && lady[mid]<height && lady[mid+1]<height){
        //cerca a destra
        return findFit(lady,height,mid+1,end);
    }
    else if(mid-1>0 && lady[mid]>height && lady[mid-1]>height){
        //cerca a sinistra
        return findFit(lady,height,mid-1,end);
    }
    else if(mid+1<lady.size() && lady[mid]<height && lady[mid+1]>height){
        Fit soluzione;
        soluzione.shorter=to_string(lady[mid]);
        soluzione.taller=to_string(lady[mid+1]);
        return soluzione;
    }
    else if(mid-1>0 && lady[mid]>height && lady[mid-1]<height){
        Fit soluzione;
        soluzione.shorter=to_string(lady[mid-1]);
        soluzione.taller=to_string(lady[mid]);
        return soluzione;
    }
    else{
        Fit soluzione;
        soluzione.shorter=to_string(lady[mid]);
        //soluzione.taller=to_string(lady[mid]);
        return soluzione;
    }

    Fit soluzione;
    return soluzione;
}


int main(){
    ifstream input("input.txt");
    if(!input){
        cerr<<"Errore nell'apertura del file"<<endl;
        return -1;
    }
    int numLady,numHeight, height;
    Fit output;

    input>>numLady;
    vector<int> lady(numLady);

    for(int i=0;i<numLady;i++){
        input>>lady[i];
    }

    input>>numHeight;

    for(int i=0;i<numHeight;i++){
        input>>height;
        output=findFit(lady,height,0,lady.size());
        cout<<output.shorter<<" "<<output.taller<<endl;
    }
}