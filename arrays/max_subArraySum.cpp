#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void printAllSubArray(vector<int> v) {
    int n = v.size();
    for(int i=0; i<n; i++) { // i is starting index
        for(int j=i; j<n; j++) { // j is ending index
            cout << "[";
            for(int k=i; k<=j; k++) {
                cout << v[k];
            }
            cout << "] ";
        }
        cout << endl;
    }
}

// O(n^2)
int bruteForce(vector<int> v) {
    int n = v.size();
    int mx = INT_MIN;
    for(int st=0; st<n; st++) {
        int currSum = 0;
        // checking for the max of all the subArray starting from index 'st'
        for(int end=st; end<n; end++) {
            currSum += v[end];
            mx = max(mx, currSum);
        }
    }
    return mx;
}

// Kadane's Algorithm 
// O(n)
int kadanes_algorithm(vector<int> v) {
    // { 3, -4, 5, 4, -1, 7, -8 }
    // make only 1 loop for every element.
    // take two variables currSum and maxSum 
    // maxSum will check for max of all of the allowed subArray (whose sum is +ve)
    // *** Whenever currSum becomes -ve , re-initialise it with 0. it basically means ki That subArray will not be included in the max sum subArray.

    int currSum = 0, maxSum = INT_MIN;
    for(int val : v) {
        currSum += val;
        maxSum = max(maxSum, currSum);
        // we are checking this max condition before re-initialisation because of the edge-case when all elements are -ve.
        // [-1,-2,-3];
        // here ans should be -1
        // and if we do the re-initialisation before the max check then max will be zero.
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> v = {3, -4, 5, 4, -1, 7, -8};
    // printAllSubArray(v);
    // cout << bruteForce(v) << endl;
    cout << kadanes_algorithm(v) << endl;
    
    return 0;
}