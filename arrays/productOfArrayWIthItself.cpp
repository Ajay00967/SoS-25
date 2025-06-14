#include <iostream>
#include <vector>
using namespace std;

// O(n^2) and O(n) space complexity
vector<int> bruteForce(vector<int> v) {
    vector<int> ans(v.size(), 1);
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(i != j) ans[i] *= v[j];
        }
    }
    return ans;
}

// O(n)
vector<int> optimal(vector<int> v) {
    int n = v.size();
    vector<int> prefix(n), suffix(n), ans(n);
    // int p = 1;
    // for(int i=0; i<n; i++) {
    //     prefix[i] = p;
    //     p *= v[i];
    // }
    // p = 1;
    // for(int i=n-1; i>=0; i--) {
    //     suffix[i] = p;
    //     p *= v[i];
    // }
    prefix[0] = suffix[n-1] = 1;
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] * v[i-1];
    }
    for(int i=n-2; i>=0; i--) {
        suffix[i] = suffix[i+1] * v[i+1];
    }
    for(int i=0; i<n; i++) {
        ans[i] = prefix[i]*suffix[i];
    }
    return ans;
}

// O(n) and space O(1)
vector<int> mostOptimal(vector<int> v) {
    int n = v.size();
    vector<int> ans(n,1);
    
    int prefix = 1;
    for(int i=0; i<n; i++) {
        ans[i] *= prefix;   // can also do this : ans[i] = ans[i-1] * v[i-1] for i>0 ;
        prefix *= v[i];
    }

    int suffix = 1;
    for(int i=n-1; i>=0; i--) {
        ans[i] *= suffix;
        suffix *= v[i];
    }

    return ans;
}

// WRONG according to the question statement !!!
// Using the division operator
vector<int> bruteForce2(vector<int> v) {
    int p = 1;
    for(auto ele : v) p *= ele;
    vector<int> ans(v.size());
    for(int i=0; i<v.size(); i++) ans[i] = (p / v[i]);
    return ans;
}

int main() {
    // Given an array
    // return an array which is such that :
    // the ith element is the product of element at position other than i.
    // And the division operator is not allowed;
    vector<int> v = {1,2,3,4};
    // vector<int> ans = bruteForce(v);
    // vector<int> ans = optimal(v);
    vector<int> ans = mostOptimal(v);
    for(int i=0; i<v.size(); i++) {
        cout << ans[i] << " \n"[i+1 == v.size()];
    }

    return 0;
}