#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vsi = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;

void getPaths(vvi & maze, int r, int c, vsi & ans, string path, vvb & visited) {
    int n = maze.size();
    // Base Cases :
    if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0 || visited[r][c]) {
        return;
    }
    if(r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    visited[r][c] = true;

    getPaths(maze, r-1, c, ans, path+"U", visited); // Going UP
    getPaths(maze, r+1, c, ans, path+"D", visited); // Going Down
    getPaths(maze, r, c-1, ans, path+"L", visited); // Going Left
    getPaths(maze, r, c+1, ans, path+"R", visited); // Going Right

    visited[r][c] = false; // Imp : Backtracking (we are marking visited as True in One path Only)
}

// Space Optimized
void getPaths2(vvi & maze, int r, int c, vsi & ans, string path) {
    int n = maze.size();
    // Base Cases :
    if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0) {
        return;
    }
    if(r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    } 
    // if we reached here --> maze[r][c] is ONE
    // Now mark this as ZERO (for visited)

    maze[r][c] = 0; // or can assign any value(say k) then add a condition in base case maze[r][c]==k for returning.

    getPaths2(maze, r-1, c, ans, path+"U"); // Going UP
    getPaths2(maze, r+1, c, ans, path+"D"); // Going Down
    getPaths2(maze, r, c-1, ans, path+"L"); // Going Left
    getPaths2(maze, r, c+1, ans, path+"R"); // Going Right

    maze[r][c] = 1; 
}

vsi findPaths(vvi &mat) {
    int n = mat.size();

    // Using a visited matrix
    vvb visited(n, vb(n, false));
    vsi ans;
    string path = "";
    getPaths(mat, 0, 0, ans, path, visited);

    // Without using the visited matrix
    vsi ans2;
    string path2 = "";
    getPaths2(mat, 0, 0, ans2, path2);

    return ans2;
}

int main() {
    /*
    # Given a nxn maze in form of a vvi consisting of 0s and 1s
    # task is to find the total number of ways in which a rat can go from (0,0) to (n-1,n-1)
    # rat can go in any of the four directions(if inside the maze)
    # with the constraints :
        1) cannot go in a cell with 0 val

    # return ans as a vector if strings (each string representing a path using L,R,U,D --> left,right,up,down)
    */

    /*
    # If we are at a cell with coordinates (r, c)
        U ==> (r-1, c)
        D ==> (r+1, c)
        L ==> (r, c-1)
        R ==> (r+1, c)
    */

    vvi maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vsi ans = findPaths(maze);

    for(auto x : ans) cout << x << endl;


    return 0;
}