#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

// O(n^3)
vector<vector<int>> fourSum(vi& arr, int tar) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vi> ans;

    for(int i=0; i<n; i++) {
        if(i && arr[i]==arr[i-1]) continue;
        for(int j=i+1; j<n; j++) {
            if(j > (i+1) && arr[j]==arr[j-1]) continue; // instead of this see below ---- (A)
            int newTar = tar - arr[i] - arr[j];

            int l = j+1, r = n-1;
            while(l < r) {
                int sum = arr[l] + arr[r];

                if(sum == newTar) {
                    ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                    l++, r--;
                    while(l < r && arr[l] == arr[l-1]) l++;
                } else if(sum > newTar) {
                    r--;
                } else {
                    l++;
                }
            }

            // while(j < n && arr[j]==arr[j-1]) j++; // ---- (A)  ==> to avoid duplicate j's
            // j--;
        }
    }

    return ans;
}

int main() {
    // LeetCode : 18
    // given an array 
    // find 4 such elements , s.t. their sum is equal target (4 element at different indexes)

    vi a = {-2, -1, -1, 1, 1, 2, 2};

    auto ans = fourSum(a, 0);

    for(auto x : ans) {
        cout << "[";
        for(int i=0; i<x.size(); i++) cout << x[i] << ",]"[i+1 == x.size()];
        cout << "\n";
    }

    
    return 0;
}