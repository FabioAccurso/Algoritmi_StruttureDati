#include<iostream>
#include<vector>
using namespace std;

struct maximum_subarray
{
    int totale;
    char who; //e=entrambi s=sinistra d=destra n=nessuno
};



maximum_subarray divide_et_impera(vector<int>& nums, int ini, int fin){
    if(ini==fin){
        maximum_subarray a;
        if(nums[ini]>0){
            a.totale=nums[ini];
            a.who='e'; 
            return a;
        }
        else{
            a.totale=nums[ini];
            a.who='n';
            return a;
        }
        
    }
    else{
        int middle=(ini + fin)/2;
        maximum_subarray sx = divide_et_impera(nums,ini,middle);
        maximum_subarray dx = divide_et_impera(nums,middle+1,fin);\

        if(sx.totale>0 && dx.totale>0){ //tutti e due positivi
            sx.totale+=dx.totale;
            sx.who='e';
            return sx;
        }

        //casi in cui solo uno e' positivo ma ne deve valere la pena tenere il negativo
        else if(dx.totale>0 && sx.totale<=0){

        }
        else if(sx.totale>0 && dx.totale<=0){

        }
        
    }
    


}


int maxSubArray(vector<int>& nums) {
    maximum_subarray soluzione = divide_et_impera(nums,0,nums.size()-1);

    return soluzione.totale;
}



int main(){
    vector<int> nums;
    int soluzione = maxSubArray(nums);
    cout<<"La somma degli elementi del massimo sotto array e': "<<soluzione<<endl;

    return 0;
}