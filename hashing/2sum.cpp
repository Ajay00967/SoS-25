#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

// O(n^2)
pair<int, int> bruteForce(vi arr, int tar) {
    int n = arr.size();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if((arr[i]+arr[j])==tar) return {i,j};
        }
    }
    return {};
}

// O(n logn)
pair<int, int> better(vi arr, int tar) {
    vi copy(arr);
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int st = 0, end = n - 1;
    int x = -1, y = -1;
    bool found = false;

    while (st <= end) {
        int sum = arr[st] + arr[end];
        if (sum == tar) {
            x = arr[st], y = arr[end];
            found = true;
            break;
        } else if (sum < tar) {
            st++;
        } else {
            end--;
        }
    }
    if (!found) return {-1, -1}; // or some sentinel value

    // Find the first occurrence of x and y in the original array
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < copy.size(); ++i) {
        if (copy[i] == x && idx1 == -1) idx1 = i;
        else if (copy[i] == y && idx2 == -1 && i != idx1) idx2 = i;
    }

    if (idx1 != -1 && idx2 != -1)
        return {idx1, idx2};
    else
        return {-1, -1};
}

// O(n)
pair<int, int> hashing(vi arr, int tar) {
    // this unordered map will store <val, idx> pair of arr values
    unordered_map<int, int> m;

    for(int i=0; i<arr.size(); i++) {
        int sec = tar - arr[i];

        if(m.find(sec) != m.end()) { // in practical cases it is generally O(1) and in rare cases it is O(n)
            return {m[sec], i};
        } else {
            m[arr[i]] = i;
        }
    }

    return {};
}


int main() {
    // LeetCode : 1
    // given an array, return idx of a pair sum of whose values is target
    // brute force :=> check for all possible pairs --> O(n^2)
    // better :=> sort the array then check --> O(nlogn)
    // optimal :=> hashing

    // Hashing is basically using maps and sets 
    
    vi arr = {5,2,11,7,15};
    int tar = 9;

    // auto p = bruteForce(arr, tar);
    // cout << p.first << " " << p.second << endl;
    // p = better(arr, tar);
    // cout << p.first << " " << p.second << endl;
    
    pair p = hashing(arr, tar);
    cout << p.first << " " << p.second << endl;



    return 0;
}