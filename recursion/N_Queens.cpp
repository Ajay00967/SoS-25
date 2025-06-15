#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vvs = vector<vs>;

bool safe(vs& board, int row, int col, int n) {
    // check for horizontal, vertical and diagonal attack 
    // no need to check for lower rows

    // horizontal
    for(int j=0; j<n; j++) {
        if(board[row][j] == 'Q') return false;
    }

    // vertical
    for(int i=0; i<=row; i++) {
        if(board[i][col] == 'Q') return false;
    }

    // upper left diagonal
    for(int i=row,j=col; i>=0 && j>=0; i--,j--) {
        if(board[i][j] == 'Q') return false;
    }

    // upper right diagonal
    for(int i=row,j=col; i>=0 && j<n; i--,j++) {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

// O(n!)
void nQueens(vs& board, int row, int n, vvs& ans) {
    if(row == n) {
        ans.push_back({board});
        return;
    }
    for(int i=0; i<n; i++) { // column no. in the row
        if(safe(board, row, i, n)) {
            board[row][i] = 'Q';
            nQueens(board, row+1, n, ans);
            board[row][i] = '.'; // backtracking
        }
    }
}

int main() {
    /*
    Given a nxn chessBoard, place N queens such that no two queens attach each other
    such all of N queens will be in a different row, obviously. 
    */
    int n = 4;

    // string empty = "";
    // for(int i=0; i<n; i++) {
    //     empty += '.';
    // }

    vs board(n, string(n,'.'));
    vvs ans;

    nQueens(board, 0, n, ans);

    if(ans.size() == 0) {
        cout << "No Combinations found\n";
        return 0;
    } else {
        cout << "Total Combination : " << ans.size() << endl;
    }

    for(auto v : ans) {
        cout << "------------\n";
        for(auto str : v) {
            cout << str << endl;
        }
        cout << endl;
    }
    cout << "------------\n";

    
    return 0;
}