/*Given a square maze containing positive numbers, find all paths from a corner
cell (any of the extreme four corners) to the middle cell. We can move exactly
n steps from a cell in 4 directions i.e. North, East, West and South where n is value of the cell, 

We can move to mat[i+n][j], mat[i-n][j], mat[i][j+n], and mat[i][j-n] from a
cell mat[i][j] where n is value of mat[i][j].

Example

Input:  5 x 5 maze

3 2 1 2 1 
1 1 2 3 2 
2 1 0 1 2 
3 3 2 1 1 
2 2 1 1 3 


Output:
esempio
(0, 0) -> (0, 3) -> (3, 3) -> 
(2, 3) -> (2, 2) -> MID
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<vector<int>> direzioni = {{1,0},{0,1},{-1,0},{0,-1}}; //ovvero le 4 direzioni in cui posso spostarmi->destra,giu,sinistra,su



bool is_solution(int n){
    return n==0;
}
bool is_safe(int rig, int col, int rMax, int cMax){
    return (rig>=0 && rig<=rMax && col>=0 && col<=cMax);
}
void process_solution(const vector<vector<int>>& result) {
    for(int i = 0; i < result.size(); i++) {
        cout << "(" << result[i][0] << ", " << result[i][1] << ")";
        if (i < result.size() - 1) cout << " -> ";
    }
    cout << " -> MID" << endl;
}

// Usa la distanza Manhattan per calcolare la "vicinanza"
bool migliore(int newR, int newC, int oldR, int oldC, int targetRow, int targetCol) {
    int newDist = abs(targetRow - newR) + abs(targetCol - newC);
    int oldDist = abs(targetRow - oldR) + abs(targetCol - oldC);
    return newDist < oldDist; // Se è più vicino al target, ritorna true
}

void backtrack(vector<vector<int>>& result, int rig, int col, vector<vector<int>>& maze){    
    result.push_back({rig,col});
    int n = maze[rig][col];
    if(is_solution(n)){
        process_solution(result);
        return;
    }
    else{
        for(int i=0;i<direzioni.size();i++){
            int rigaNew = rig + (direzioni[i][0] * n);
            int colonnaNew = col + (direzioni[i][1] * n);

            //controllo se la nuova posizione è safe ed è migliore della precedente in cui stavo
            if(is_safe(rigaNew, colonnaNew, maze.size()-1, maze[0].size()-1) && migliore(rigaNew,colonnaNew, rig, col, (maze.size())/2,(maze[0].size())/2)){

                backtrack(result, rigaNew, colonnaNew,maze);
                result.pop_back();
            }
        }
    }
    return;
}

int main(){
    vector<vector<int>> maze = {{3,2,1,2,1},{1,1,2,3,2},{2,1,0,1,2},{3,3,2,1,1},{2,2,1,1,3}};
    vector<vector<int>> result;
    backtrack(result,0,0,maze);
}