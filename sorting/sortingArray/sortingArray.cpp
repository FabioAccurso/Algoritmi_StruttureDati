/*https://www.geeksforgeeks.org/sorting-in-array/*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void merge(vector<int>& arr, int init, int mid, int end){
    int n1 = mid-init+1;
    int n2 = end-mid;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    //Riempio L e R
    for(int i=0;i<n1;i++){
        L[i]=arr[init+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+i+1];
    }

    L[n1]=INT_MAX;
    R[n2]=INT_MAX;

    int i=0;
    int j=0;

    for(int k=init;k<=end;k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& arr,int init,int end){
    if(init<end){
        int mid=(init+end)/2;
        mergeSort(arr,init,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,init,mid,end);
    }
}





int main(){
    vector<int> array = {5,2,4,3,1};
    cout<<"Array Pre-Ordinamento -> [ ";
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<"]"<<endl;

    mergeSort(array,0,array.size()-1);

    cout<<"Array Post-Ordinamento -> [ ";
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<"]"<<endl;
}