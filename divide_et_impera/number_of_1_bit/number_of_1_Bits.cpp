/*
https://leetcode.com/problems/number-of-1-bits/description/?envType=problem-list-v2&envId=divide-and-conquer
Given a positive integer n, write a function that returns the number of set bits in its binary representation */

/* Complessita' della mia soluzione -> O(log(n)) */
#include<iostream>
#include<vector>
#include <cmath>
using namespace std;


int divide_et_impera(int n, int& sum){
    //Quando raggiungo zero allora ho terminato il conteggio dei bit alti.
    if(n==0){
        return sum;
    }
    else{
        //calcolo il logaritmo in base 2 e lo approssimo per difetto usando floor,
        //ottenendo cosi la posizione dell'1 piu' a sinistra nella rappresentazione binaria
        int esponente = floor(log2(n));
        //Calcolo 2^(esponente) con l'operatore di bit. Avrei anche potuto usare il metodo pow.
        //Questo sposta il bit 1 verso sinistra di un numero di posizioni pari all'esponente, il che equivale a calcolare 2 elevato all'esponente.
        int da_sottrarre = 1 << esponente;
        //sottraggo cio' che ho ottenuto ad n
        n = n - da_sottrarre;
        //aggiorno la somma di bit alti
        sum = sum + 1;
        //richiamo ricorsivamente la funzione che all' n-esima iterazione ritornera' sum -> somma di bit alti
        return divide_et_impera(n,sum);
    }
}


//potevo chiamare direttamente dal main divide_et_impera ma uso questa funzione di appoggio
//in modo da poterla testare su leetcode con tutti i casi di test.
int hammingWeight(int n) {
    int output = 0, sum = 0; 
    output = divide_et_impera(n,sum);
    return output;
}

int main(){
    int numeroInput = 11;
    int output = 0; 

    output = hammingWeight(numeroInput);

    cout<<"Il numero di bit alti e' pari a -> "<<output;
}