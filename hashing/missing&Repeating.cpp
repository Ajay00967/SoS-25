#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

// optimal
vi missing_repeating(vector<vi> grid) {
    unordered_set<int> s;
    // vector<bool> seen(n*n+1, false) // better to use this
    vi ans;
    int n = grid.size();
    int a = 0;
    long long int sum = 0;
    bool found = false;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int val = grid[i][j];
            sum += val;
            if(!found && s.find(val) != s.end()) {
                a = val;
                ans.push_back(a);
                found = true;
            }
            s.insert(val);
        }
    }
    sum -= a;

    long long int expSum = 1LL*n*n*(n*n + 1) / 2;

    int b = expSum - sum;

    return {a, b};
}

// my solution
vi find_Missing_Repeating(vector<vi> grid) {
    unordered_map<int, int> freq;

    int n = grid.size();
    int a, b;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            freq[grid[i][j]]++;
            if(freq[grid[i][j]] == 2) b = grid[i][j];
        }
    }

    for(int i=1; i<=n*n; i++) {
        if(freq.find(i) == freq.end()) a = i;
    }

    return {a,b};
}

int main() {
    // LeetCode : 2965
    // given a square matrix(of size n) 
    // with all entries from 1 to n^2 except a (missing) because b is repeated twice
    // find a and b;

    vector<vi> grid = {{9,1,7}, {8,9,2}, {3,4,6}};
    vi ans = find_Missing_Repeating(grid);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}