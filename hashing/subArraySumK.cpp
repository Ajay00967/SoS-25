#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

// O(n^2)
int bruteForce(vi & arr, int k) {
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];

            if(sum == k) count++;
        }
    }
    return count;
}

// O(n) & O(n)
int subArray(vi & arr, int k) {
    /*
    use of prefix-sum
    prefix-sum of a index is the sum all element before that
    e.g : 
    arr = [1,2,3,4,5]
    ps[i] = arr[0]+arr[1]+arr[2]+...+arr[i];
    (1) subArraySum(i,j) = ps[j] - ps[i-1]
    (2) if we know one ps, then also the other, ps[i-1] = ps[j]-k;

    we will run a loop for j and check if ps[i-1] exist or not 
    */
    int n = arr.size(), count = 0;
    vi prefixSum(n, 0);
    prefixSum[0] = arr[0];

    unordered_map<int, int> m;
    // m[arr[0]]++;
    
    for(int i=1; i<n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
        // m[prefixSum[i]]++;
    }

    for(int j=0; j<n; j++) {
        int req = prefixSum[j] - k;
        if(req == 0) {
            count++;
        }
        if(m.find(req) != m.end()) { // this doesn't check for i<j :( ==> so we will do the hashing along with the loop (so future value won't appear)
            count += m[req];
        }
        m[prefixSum[j]]++; // this is important , doing hashing while checking
    }
    
    return count;
}

int main() {
    // LeetCode : 560
    // given an array give the count of subarrays whose sum is k

    vi v = {9, 4, 20, 3, 10, 5};
    int k = 33;

    // cout << bruteForce(v, k) << endl;
    cout << subArray(v, k) << endl;


    return 0;
}