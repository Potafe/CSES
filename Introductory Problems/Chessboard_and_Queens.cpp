/*
We do basic recursion here:

1. We start from the first row and try to place a queen in each column.
2. For each column, we check if the column and both diagonals are free.
    Diagonals are checked using the properties:
    - occupiedDiagonal1[row + col] for the main diagonal
    - occupiedDiagonal2[row - col + 8] for the anti-diagonal
*/

#include <iostream>
#include <vector>
using namespace std;

void solveRecursion(int row, int &ans, 
    vector<vector<char>> &board, vector<bool> &occupiedColumn, 
    vector<bool> &occupiedDiagonal1, vector<bool> &occupiedDiagonal2) {
    
    if (row == 8) {
        ans++;
        return;
    }
    
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '*' || occupiedColumn[col]
            || occupiedDiagonal1[row + col] || occupiedDiagonal2[row - col + 8]
        ) continue;
        
        occupiedColumn[col] = true;
        occupiedDiagonal1[row + col] = true; 
        occupiedDiagonal2[row - col + 8] = true;
        
        solveRecursion(row + 1, ans, board, occupiedColumn, occupiedDiagonal1, occupiedDiagonal2);
        
        occupiedColumn[col] = false;
        occupiedDiagonal1[row + col] = false; 
        occupiedDiagonal2[row - col + 8] = false;
    }
    
}

int main() {
    int ans = 0;
    vector<vector<char>> board(8, vector<char>(8));
    vector<bool> occupiedColumn(10, false);
    vector<bool> occupiedDiagonal1(20, false);
    vector<bool> occupiedDiagonal2(20, false);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char x;
            cin >> x;
            board[i][j] = x;
        }
    }
    
    solveRecursion(0, ans, board, occupiedColumn, occupiedDiagonal1, occupiedDiagonal2);
    
    cout << ans << endl;
    return 0;
}