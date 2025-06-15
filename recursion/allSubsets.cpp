#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

// O(n * 2^n)
void printSubsets(vi arr, vi& ans, int i=0) {
    // we will just take care of a element to be or not in the subset
    // e.g : [1,2,3]  []
    // 1st step :          [1]                        []  (either include one or not)
    // 2nd step :       [1,2]  [1]                [2]    []
    // 3rd step :[1,2,3] [1,2]  [1,3] [1]    [2,3] [2]  [3] []
    // at last step(nth) we will get all the subsets 

    // the ans array will store the current subset of a recursion call (so passing by reference for backtracking)
    // and 'i' will track the current step.
    if(i == arr.size()) {
        // print the ans array as we found the subset.
        for(auto x : ans) cout << x << " ";
        cout << "\n";
        return;
    }

    // Including the element
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);

    // Excluding the element
    ans.pop_back(); // backtracking :)
    printSubsets(arr, ans, i+1);

    // Time Complexity :
    // At last step(leaf) all total there will be 2^n subsets
    // and each subset will be traversed by n calls
}

int main() {
    // given an array print all of its subsets 

    vi arr = {1,2,3};
    vi ans;

    // cout << ans.size() << "\n"; // 0 --> starts with zero
    printSubsets(arr, ans);
    // cout << ans.size() << "\n"; // 0 --> end with zero after all backtracking steps :)

    return 0;
}