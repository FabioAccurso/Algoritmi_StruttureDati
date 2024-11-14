#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct Fit{
    string taller="X";
    string shorter="X";
};


Fit findFit(const vector<int>& lady, int height,int init, int end){
    int mid=(init+end)/2;
    if(mid-1>=0){
        if(lady[mid]>=height && lady[mid-1]<=height){
            //assegna
            Fit soluz;
            if(lady[mid]!=height)soluz.taller=to_string(lady[mid]);
            else soluz.taller=to_string(lady[mid+1]);
            if(lady[mid-1]!=height)soluz.shorter=to_string(lady[mid-1]);
            else soluz.shorter=to_string(lady[mid-2]);
            return soluz;
        }
        else if(lady[mid-1]>=height){
            return findFit(lady,height,init,mid-1);
        }
    }
    if(mid+1<lady.size()){
        if(lady[mid]<=height && lady[mid+1]>=height){
            //assegna
            Fit soluz;
            if(lady[mid]!=height)soluz.shorter=to_string(lady[mid]);
            else soluz.shorter=to_string(lady[mid-1]);
            if(lady[mid+1]!=height)soluz.taller=to_string(lady[mid+1]);
            else soluz.taller=to_string(lady[mid+2]);
            return soluz;
        }
        else if(lady[mid]<=height && lady[mid+1]<=height){
            return findFit(lady,height,mid+1,end);
        }

    }
    if(mid-1<0 || mid+1>=lady.size()){
        Fit soluzione;
        if(lady[mid]>height) soluzione.taller=to_string(lady[mid]);
        else if(lady[mid]<height) soluzione.shorter= to_string(lady[mid]);
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
    cout<<"Lady -> [ ";
    for(int i=0;i<numLady;i++){
        input>>lady[i];
        cout<<lady[i]<<" ";
    }
    cout<<"]"<<endl;

    input>>numHeight;

    for(int i=0;i<numHeight;i++){
        input>>height;
        output=findFit(lady,height,0,lady.size());
        cout<<"[H = "<<height<<"] -> ";
        cout<<output.shorter<<" "<<output.taller<<endl;
    }
}