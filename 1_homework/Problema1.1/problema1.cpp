#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int find_max_elem(vector<int> v, int begin, int end){

    int index=ceil((begin+end)/2);

    if(v[index]>v[(index)-1] && v[index]<v[(index)+1]){
        return find_max_elem(v, (index)+1, end);
    }

    else if(v[index]<v[(index)-1] && v[index]>v[(index)+1]){
        return find_max_elem(v, begin, (index)-1);
    }

    else{
        return v[index];
    }

}

int main(){
    
    vector<int> v = {1, 3, 20, 15, 12, 10, 7, 5, 3, 1, 0};
    vector<int> v1 = {1, 10, 2};
    vector<int> v2 = {1, 4, 5, 7, 8, 9, 15, 2};   
    cout<<"Il massimo elemento di v e': "<<find_max_elem(v, 0, v.size()-1)<<endl;;
    cout<<"Il massimo elemento v1 e': "<<find_max_elem(v1, 0, v1.size()-1)<<endl;
    cout<<"Il massimo elemento v2 e': "<<find_max_elem(v2, 0, v2.size()-1)<<endl;

}