#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void allSubsets(vi arr, vi ans, int i, vector<vi>& powerSet) {
    if(i == arr.size()) {
        powerSet.push_back({ans});
        return;
    }

    ans.push_back(arr[i]);
    allSubsets(arr, ans, i+1, powerSet);

    ans.pop_back();
    allSubsets(arr, ans, i+1, powerSet);
}

int main() {
    // LeetCode : 78
    // store all the subset of a array in a vector of vectors

    vi arr = {1,2,3,4};
    vi ans = {};

    vector<vi> powerSet;

    allSubsets(arr, ans, 0, powerSet);

    auto n = powerSet.size();
    for(auto j=0; j<n; j++) {
        if(j < n-1) cout << "{";
        auto m = powerSet[j].size();
        for(auto i=0; i<m; i++) {
            cout << powerSet[j][i] << ",}"[i+1 == m];
        }
        cout << endl;
    }

    return 0;
}