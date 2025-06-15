#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

// O(n * n!) & O(n!)
void getPerms(vi& arr, int idx, vector<vi>& ans) {
    // we have arr.size() positions 
    // we'll fill one at a time
    // we will not use a extra space
    // we will swap the idx val to it next and then next and so on..
    int n = arr.size();

    if(idx == n) {
        for(auto x : arr) cout << x << " ";
        cout << endl;
        ans.push_back({arr});
        return;
    }

    for(int i=idx; i<n; i++) {
        swap(arr[idx], arr[i]);
        getPerms(arr, idx+1, ans);
        swap(arr[idx], arr[i]); // for backtracking (because we are passing arr by reference)
    }
}

void printPermsString(string& arr, int idx=0) {
    int n = arr.size();

    if(idx == n) {
        for(auto x : arr) cout << x << " ";
        cout << endl;
        return;
    }

    for(int i=idx; i<n; i++) {
        swap(arr[idx], arr[i]);
        printPermsString(arr, idx+1);
        swap(arr[idx], arr[i]);
    }
}

int main() {
    vi v = {1, 2, 3, 4};
    // Given an array (or string), give all of its permutations
    vector<vi> ans;
    getPerms(v, 0, ans);

    string s = "abc";
    printPermsString(s);

    return 0;
}