#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

bool safe(vvc & board, int row, int col, char val) {
    // In Row
    for(int j=0; j<9; j++) {
        if(board[row][j] == val) return false;
    }

    // In Column
    for(int i=0; i<9; i++) {
        if(board[i][col] == val) return false;
    }

    // In 3x3 grid
    int r = row/3, c = col/3;
    r *= 3, c *= 3; // starting point of a grid
    for(int i=r; i<r+3; i++) {
        for(int j=c; j<c+3; j++) {
            if(board[i][j] == val) return false;
        }
    }

    return true;
}

bool solve(vvc & board, int row, int col) {
    // Base Case
    if(row == 9) return true; // only case returning true (obviously)

    int r = row, c = col + 1; // next row and col logic
    if(c == 9) {
        r = row + 1;
        c = 0;
    }

    if(board[row][col] != '.') { // if already filled --> next cell's call
        return solve(board, r, c);
    }

    // If cell is empty 
    // place a valid number 
    for(char dig='1'; dig<='9'; dig++) {
        if(safe(board, row, col, dig)) {
            board[row][col] = dig;

            if(solve(board, r, c)) {
                return true;
            }
            board[row][col] = '.'; // Backtracking 
        }
        // changes the digit
    }
    return false;
}

int main() {
    // solve a given sudoku problem, provided it has only one possible solution.
    vvc board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool a = solve(board, 0, 0);

    if(!a) return 0;

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << board[i][j] << " \n"[j==8];
        }
    }
    

    return 0;
}