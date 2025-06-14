#include <iostream>
#include <vector>
using namespace std;

// O(log n) and O(1)
int singleElement(vector<int> v) {
    // the number of element in v will be odd
    int n = v.size();
    if(n==1) return v[0];

    int st = 0, end = n-1;

    while( st <= end ) {
        int mid = st + (end - st)/2;

        // edge cases :
        if(mid == 0 && v[0] != v[1]) return v[0];
        if(mid == n-1 && v[n-1] != v[n-2]) return v[n-1];

        // single element check 
        if( v[mid-1] != v[mid] && v[mid] != v[mid+1] ) return v[mid];
        // after this check it is confirmed that v[mid] is equal to either previous or the next.

        // main logic :
        if( mid % 2 == 0 ) { // even on left side
            if( v[mid] == v[mid-1] ) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        } else { // odd on left side
            if( v[mid] == v[mid-1] ) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    // given an sorted array with all element twice expect one which is occurring only once.
    // task is to find that single element :)
    vector<int> v = {1,1,2,3,3,4,4,8,8};
    cout << singleElement(v) << endl;

    return 0;
}