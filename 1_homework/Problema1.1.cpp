#include <iostream>
using namespace std;

int main()
{
    int dimArray=20;
    int A[dimArray]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,4,3};
    
    int n=0 , m=dimArray;
    cout<<"Test";
    int centro=((m-n)/2), max=0;
    
    cout<<centro;
    
    while(n<m){
        if(A[centro]<A[centro+1]){
            n=centro;
            centro=(m-n)/2;
        }
        else if(A[centro]<A[centro-1]){
            m=centro;
            centro=(m-n)/2;
        }
        else{
            max=A[centro];
            break;
        }
    }
    if(n==m){
        max=A[centro];
    }
    
    cout<<"Il massimo è: "<<max;
}