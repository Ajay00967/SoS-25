#include <iostream>
using namespace std;

// O(n)
int linearSearch(int arr[], int size, int target) {
    for(int i=0; i<size; i++) {
        if(target == arr[i]) return i;
    }
    return -1;
}

int main() {
    int nums[] = {4, 2, 7, 8, 1, 2, 5};
    int size = sizeof(nums)/sizeof(int);

    // int target = 48;
    // int idx = -1;
    // for(int i=0; i<size; i++) {
    //     if( target == nums[i] ) {
    //         idx = i;
    //     }
    // }

    cout << linearSearch(nums, size, 8) << endl;

    return 0;
}