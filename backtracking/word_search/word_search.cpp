/*https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=backtracking*/
/*Given an m x n grid of characters board and a string word, return true if word exists in the grid./*
/*The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.*/

#include<iostream>
#include<vector>
using namespace std;

bool is_solution(string word, int wordFind){
    return word.size()==wordFind;
}
bool is_safe(int rig, int col,int rMax, int cMax){
    return (rig >= 0 && rig < rMax && col >= 0 && col < cMax); //controlla che non esco dalla matrice
}


void backtrack(vector<vector<char>>& board, const string& word, int wordFind,int rig, int col, bool& result, vector<vector<bool>>& visited){
    if (result) return;
    if(is_solution(word,wordFind)){
        result = true;
        return;
    }
    else{
        //se ho gia' almeno una lettera devo guadarmi intorno in tutte le direzioni possibili.
        if(wordFind!=0){
            //controllo in ogni direzione sia se non esco da matrice e sia se trovo la prossima lettera che cerco. Controllo inoltre che la cella non sia gia stata visitata
            // Per ogni direzione faccio make_move, backtrack e unmake_move. <- Avrei potuto usare dei metodi chiamati cosi per semplificare codice

            //destra
            if(is_safe(rig,col+1,board.size(),board[0].size()) && board[rig][col+1] == word[wordFind] && visited[rig][col+1]==false){
                wordFind=wordFind+1;
                visited[rig][col+1]=true;
                backtrack(board,word,wordFind,rig,col+1,result,visited);
                if (result) return;
                wordFind=wordFind-1;
                visited[rig][col+1]=false;
            }
            //sotto
            if(is_safe(rig+1,col,board.size(),board[0].size()) && board[rig+1][col] == word[wordFind] && visited[rig+1][col]==false){
                wordFind=wordFind+1;
                visited[rig+1][col]=true;
                backtrack(board,word,wordFind,rig+1,col,result,visited);
                if (result) return;
                wordFind=wordFind-1;
                visited[rig+1][col]=false;
            }
            //sinistra
            if(is_safe(rig,col-1,board.size(),board[0].size()) && board[rig][col-1] == word[wordFind] && visited[rig][col-1]==false){
                wordFind=wordFind+1;
                visited[rig][col-1]=true;
                backtrack(board,word,wordFind,rig,col-1,result,visited);
                if (result) return;
                wordFind=wordFind-1;
                visited[rig][col-1]=false;
            }
            //sopra
            if(is_safe(rig-1,col,board.size(),board[0].size()) && board[rig-1][col] == word[wordFind] && visited[rig-1][col]==false){
                wordFind=wordFind+1;
                visited[rig-1][col]=true;
                backtrack(board,word,wordFind,rig-1,col,result,visited);
                if (result) return;
                wordFind=wordFind-1;
                visited[rig-1][col]=false;
            }
            
            return;
        }
        //se non ho trovato ancora la prima lettera scorro semplicemente matrice e confronto casella per casella alla ricerca della prima lettera
        else{
            for(int i=0;i<board.size();i++){ //il for piu' esterno scorre le righe
                for(int j=0;j<board[0].size();j++){ // quello piu' interno le colonne
                    if(board[i][j]==word[0]){
                        wordFind=wordFind+1;
                        visited[i][j]=true;
                        backtrack(board,word,wordFind,i,j,result,visited);
                        if (result) return;
                        wordFind=wordFind-1;
                        visited[i][j]=false;
                    }
                }
            }
            return;
        }
    }
}


bool exist(vector<vector<char>>& board, const string& word) {
    int wordFind=0;
    int rig=0,col=0;
    bool result=false;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    backtrack(board,word,wordFind,rig,col, result,visited);

    return result;
}


int main(){
    vector<vector<char>> input = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "BCCFDEE";
    bool output = exist(input,word);
    
    if(output){
        cout<<"[Vero] La sequenza ricercata esiste! :)";
    }
    else{
        cout<<"[Falso] La sequenza ricercata NON esiste! :(";
    }
}
