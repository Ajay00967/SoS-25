#include <iostream>
#include <vector>
using namespace std;

// O(log n)
int peak(vector<int> v) {
    // the end value will never be the peak, so we are starting with idx 1 and n-2;
    int st = 1, end = v.size()-2;

    //                 /\
    //                /  \
    //               /    \
    //              /      \
    //             /        \
    // if mid lies on the left , then st = mid + 1;
    // else if mid lies on the right, then end = mid - 1;

    while( st <= end ) {
        int mid = st + (end - st)/2;

        if( v[mid] > max(v[mid-1], v[mid+1]) ) return mid;

        if( v[mid-1] < v[mid] ) { // v[mid-1] < v[mid] && v[mid] < v[mid+1]
            st = mid + 1;
        } else if( v[mid-1] > v[mid] ) { // v[mid-1] > v[mid] && v[mid] > v[mid+1]
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    // given a mountain array with peak element
    // the array was increasing till peak element and decreasing after peak element
    vector<int> v = {0, 3, 8, 9, 5, 2};

    cout << peak(v) << endl;

    return 0;
}