
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct Fit{
    string taller="X";
    string shorter="X";
};

Fit findFit(const vector<int>& lady, int height){
    Fit solution;
    bool findTall=false;

    for(int i=0;i<lady.size();i++){
        if(!findTall && lady[i]>height){
            findTall=true;
            solution.taller=to_string(lady[i]);
        }
        else if(lady[i]<height){
            solution.shorter=to_string(lady[i]);
        }
    }
    return solution;
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
        output=findFit(lady,height);
        cout<<output.shorter<<" "<<output.taller<<endl;
    }
}