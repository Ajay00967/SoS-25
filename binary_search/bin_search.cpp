#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

// O(log n) and space O(1)
// Iterative method
int binarySearch(vector<int> v, int target) {
    int st = 0, end = v.size() - 1;
    while(st <= end) {
        // int mid = (st + end)/2;
        int mid = st + (end - st)/2;
        if( target == v[mid] ) {
            return mid;
        } else if( target > v[mid] ) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

// O(log n) and space O(n)
// Recursive Method
int recursive(vector<int> v, int st, int end, int tar) {
    if( st > end ) return -1;
    int mid = st + (end - st)/2;
    if( tar == v[mid] ) {
        return mid;
    } else if( tar > v[mid] ) {
        return recursive(v, mid+1, end, tar);
    } else {
        return recursive(v, st, mid-1, tar);
    }
}

int main() {
    vector<int> v = {-1, 0, 3, 4, 5, 9, 12};
    int target = 12;

    // cout << binary_search(v.begin(), v.end(), target) << endl; // from the algorithm library
    cout << binarySearch(v, target) << endl;
    cout << recursive(v, 0, v.size()-1, target) << endl;

    return 0;
}