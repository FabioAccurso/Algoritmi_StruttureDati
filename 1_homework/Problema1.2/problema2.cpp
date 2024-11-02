#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

string trovaPrefisso(string parola1, string parola2){
    string prefix="";
    int m = min(parola1.length(), parola2.length());
    
    for(int i=0; i<m;i++){
        if(parola1[i]==parola2[i]){
            prefix+=parola1[i];
        }
        else{
            break;
        }
    }
    return prefix;
}

string confrontaVettoreStringhe(vector<string>& strs, int init, int end){
    string prefix="";
    string pref1, pref2;

    if(strs.size()>0){
        if(end - init >0){
            int centro = ((init + end)/2);
            pref1=confrontaVettoreStringhe(strs,init, centro);
            pref2=confrontaVettoreStringhe(strs, centro+1,end);

            prefix=trovaPrefisso(pref1,pref2);
        }
        else{
            prefix=strs[init];
        }
    }

    return prefix;
}


int main(){
    vector<string> strs_1={"apple","ape","april","applied"};
    vector<string> strs_2={"capital","car","catch","card","call","center","can"};
    vector<string> strs_3={"dream","draw","energy","end"};
    vector<string> strs_4={"leader","leave","learn"};
    vector<string> strs_5={"test"};

    string prefisso_1=confrontaVettoreStringhe(strs_1, 0, strs_1.size()-1);
    string prefisso_2=confrontaVettoreStringhe(strs_2, 0, strs_2.size()-1);
    string prefisso_3=confrontaVettoreStringhe(strs_3, 0, strs_3.size()-1);
    string prefisso_4=confrontaVettoreStringhe(strs_4, 0, strs_4.size()-1);
    string prefisso_5=confrontaVettoreStringhe(strs_5, 0, strs_5.size()-1);

    vector<string> prefisso={prefisso_1,prefisso_2,prefisso_3,prefisso_4,prefisso_5};
    for(int i=0;i<prefisso.size();i++){
        if(prefisso[i].empty()){
            cout << "Per il caso di test "<<i+1<<" non c'è un prefisso comune." << endl;
        }
        else{
            cout<<"Per il caso di test "<<i+1<<" il prefisso piu' lungo e':  '"<<prefisso[i]<<"'"<< endl;
        }
    }

    return 0;
}