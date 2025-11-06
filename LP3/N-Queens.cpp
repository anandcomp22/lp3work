#include <bits/stdc++.h>
using namespace std;

// Function to print one valid board configuration
void printBoard(vector<vector<int>> &board, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Check if a queen can be placed at board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    // Check column above
    for(int i = 0; i < row; i++)
        if(board[i][col]) return false;

    // Check upper left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if(board[i][j]) return false;

    // Check upper right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < N; i--, j++)
        if(board[i][j]) return false;

    return true;
}

// Recursive function to solve N Queens
bool solveNQueen(vector<vector<int>> &board, int row, int N) {
    // Base case: All queens are placed
    if(row == N) {
        printBoard(board, N);
        return true;
    }

    bool res = false;
    for(int col = 0; col < N; col++) {
        if(isSafe(board, row, col, N)) {
            board[row][col] = 1;  // Place queen
            res = solveNQueen(board, row + 1, N) || res;
            board[row][col] = 0;  // Backtrack
        }
    }
    return res;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if(!solveNQueen(board, 0, N))
        cout << "No solution exists for " << N << "x" << N << " board." << endl;

    return 0;
}
