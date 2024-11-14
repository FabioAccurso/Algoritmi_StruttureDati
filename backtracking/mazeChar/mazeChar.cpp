/*Data una matrice di caratteri NxM cerca all interno di questa una parola. Puoi muoverti in tutte le direzioni (anche diagonale). Metti in output le celle visitate per trovare la parola.*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> direzioni = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

bool is_solution(int size, int dim) {
    return size == dim;
}

void process_solution(vector<vector<int>> & find) {
    for (int i = 0; i < find.size(); i++) {
        for (int j = 0; j < find[i].size(); j++) {
            cout << find[i][j] + 1 << " ";
        }
        cout << endl;
    }
    cout<<"END"<<endl;
}

bool is_safe(int r, int c, int rM, int cM) {
    return (r >= 0 && c >= 0 && r < rM && c < cM);
}



void backtrack(vector<vector<char>>& matrix, string word, vector<vector<int>> & find, int riga, int colonna,bool& trovata) {
    if (is_solution(find.size(), word.size())) {
        process_solution(find);
        trovata=true;
        return;
    }
    
    if (find.size() == 0) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == word[0]) {
                    riga = i;
                    colonna = j;
                    find.push_back({riga, colonna});
                    backtrack(matrix, word, find, riga, colonna, trovata);
                    find.pop_back();
                }
                if(trovata){
                    break;
                }
            }
            if(trovata){
                break;
            }
        }
    }
    
    if(!trovata){
        for (int i = 0; i < direzioni.size(); i++) {
            int rigaNew = riga + direzioni[i][0];
            int colNew = colonna + direzioni[i][1];
            
            if (is_safe(rigaNew, colNew, matrix.size(), matrix[0].size()) && matrix[rigaNew][colNew] == word[find.size()]) {
                find.push_back({rigaNew, colNew});
                backtrack(matrix, word, find, rigaNew, colNew,trovata);
                find.pop_back();
            }
        }
    }
}



int main(){
    vector<vector<int>> find;
    bool trovata = false;
    
    //caso test 1 -> ok, anche modificando la 'h' ,alla prima riga quarta colonna, con una 'a' trova sempre la soluzione e poi si ferma senza cercarne altre
    vector<vector<char>> matrice = {{'s', 'r', 'z', 'h', 'd'},{'f', 'o', 'a', 'g', 'e'},{'x', 'd', 'n', 'l', 'o'},{'o', 'r', 'a', 't', 'n'},{'z', 'p', 'o', 'i', 'n'}};
    string parola = "age";
    
    //caso test 2 -> ok anche il movimento in diagonale funziona perfettamente
    vector<vector<char>> matrice2 = {{'r', 't', 'r'},{'o', 'a', 'r'}};
    string parola2="ora";
    
    //caso test 3 -> ritorna due volte nella stessa casella
    vector<vector<char>> matrice3 = {{'a', 'b', 'c'},{'d', 'e', 'f'}};
    string parola3 = "aba";

    cout<<"[Caso Test 1]"<<endl;
    backtrack(matrice,parola,find,0,0,trovata);

    trovata = false; find.clear();
    cout<<"[Caso Test 2]"<<endl;
    backtrack(matrice2,parola2,find,0,0,trovata);
    
    trovata = false; find.clear();
    cout<<"[Caso Test 3]"<<endl;
    backtrack(matrice3,parola3,find,0,0,trovata);
}



/* 
Considerazioni finali:
- avrei potuto migliorare il programma aggiungendo una matrice della stessa dimensione che teneva traccia delle caselle visitate in modo da non ritornarci
- avrei ovviamente potuto fare un ciclo per i casi di test magari con una lettura da file
- tutto sommato funziona piu che bene. :)
*/