#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

// O(n^2)
void selectionSort(vi& v) {
    // assume array in two parts : sorted and unsorted
    // select the smallest element from the unsort part and put it into the sorted one
    // initially whole array is unsorted
    int n = v.size();

    for(int i=0; i<n-1; i++) {
        int smallestIdx = i;

        for(int j=i+1; j<n; j++) {
            if(v[j] < v[smallestIdx]) {
                smallestIdx = j;
            }
        }
        
        // swap(smallest, v[i]); ==> This is wrong this will swap smallest and v[i] but smallest isn't a part of array.
        swap(v[smallestIdx],  v[i]);
    }
}

int main() {
    vi v = {4, 1, 5, 2, 3};
    int n = v.size();
    selectionSort(v);
    for(int i=0; i<n; i++) {
        cout << v[i] << " \n"[i+1 == n];
    }

    return 0;
}