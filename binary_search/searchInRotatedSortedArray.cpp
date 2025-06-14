#include <iostream>
#include <vector>
using namespace std;

// O(log n)
// Modified form of binary search :)
int searchInRSA(vector<int> v, int tar) {
    int st = 0, end = v.size()-1;
    while( st <= end ) {
        int mid = st + (end - st)/2;

        if(v[mid] == tar) return mid;

        if(v[st] <= v[mid]) { // left half is sorted
            if(v[st] <= tar && tar <= v[mid]) {
                end = mid - 1;
            } else { // this will become the smaller question for search in RSA :)
                st = mid + 1;
            }
        } else if(v[mid] <= v[end]) { // right half is sorted ; we needn't to write 'else if' Because either part will be sorted
            if(v[mid] <= tar && tar <= v[end]) {
                st = mid + 1;
            } else { // this will become the smaller question for search in RSA :)
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    // a sorted array is rotated about a pivot point
    // can find the target using linear search (not optimal)

    // ******
    // for a rotated sorted array
    // Either of two half will be sorted --> because the pivot can be in only one side :)
    // check if the target is in the left or right (sorted or unsorted)
    // in the example below
    // the sorted part is {3, 4, 5} and the tar=0 can not be in this part
    vector<int> v = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << searchInRSA(v, target) << endl;

    return 0;
}