#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
int bruteForce(vector<int> v) {
    int n = v.size();
    int maxV = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int vol = (j-i) * min(v[i], v[j]);
            maxV = max(maxV, vol);
        }
    }
    return maxV;
}

// O(n)
int optimal_2_pointer(vector<int> v) {
    // the pointer with smaller height will control the volume of the container ONLY 
    // the above line is very important.
    int l = 0, r = v.size()-1;
    int maxV = 0;
    while(l < r) {
        int vol = (r-l) * min(v[l], v[r]);
        maxV = max(maxV, vol);
        v[l] < v[r] ? l++ : r--;
    }
    return maxV;
}

int main() {
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    // 1,8,6,2,5,4,8,11,10
    vector<int> a = {1,8,13,2,5,4,8,3,7};
    // cout << bruteForce(v) << endl;
    cout << optimal_2_pointer(a) << endl;

    return 0;
}