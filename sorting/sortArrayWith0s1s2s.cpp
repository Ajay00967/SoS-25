#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

// O(n) with single pass
// Dutch National Flag Algorithm
void DNF_algorithm(vi& v) {
    /******************************
    3 pointers : low, mid, high

    The vision of this algo :
    
    0 0 0 0    1 1 1    -----------    2 2 2
    |     |    |   |    |        |     |   |
    0    l-1   l  m-1   m        h    h+1 n-1

    the part b/w m and h is unsorted,
    and we will try to decrease it, and eventually to 0 --> To get Whole Sorted Part :)
    initially whole array is unsorted :)

    ******************************/

    int n = v.size();
    int mid = 0, low = 0, high = n-1;

    while(mid <= high) {
        if(v[mid] == 0) {
            swap(v[mid], v[low]);
            low++, mid++;
        } else if(v[mid] == 1) {
            mid++;
        } else {
            swap(v[mid], v[high]);
            high--;
        }
    }
}

// O(n) and 2 passes (loop)
void sortByCounting(vi& v) {
    vi count(3,0);
    for(auto a : v) {
        count[a]++;
    }
    int idx = 0;
    for(int i=0; i<3; i++) {
        while(count[i]--) {
            v[idx++] = i;
        }
    }
}

int main() {
    // Given an array with only 0, 1, 2 as its entries, sort it
    // bruteForce -> sort using algorithm ==> O(nlogn)
    // better -> count 0s, 1s, 2s
    vi v = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

    // sortByCounting(v);
    DNF_algorithm(v);

    for(auto a : v) cout << a << " ";
    cout << endl;


    return 0;
}