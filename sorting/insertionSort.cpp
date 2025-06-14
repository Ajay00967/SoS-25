#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

// O(n^2)
void insertionSort(vi& v) {
    // Initially assume first element is sorted and rest array is unsorted :)
    // from unsorted part take first element and "Insert" it its correct position
    int n = v.size();
    for(int i=1; i<n; i++) {
        int curr = v[i];
        int prev = i-1;
        while(prev >= 0) { // can also write while(prev >= 0 && v[prev] > curr); Then no need to write the else condition
            if(v[prev] > curr) {
                v[prev+1] = v[prev];
                prev--;
            } else break;
        }
        v[prev+1] = curr;
    }
}

int main() {
    vi v = {4, 1, 5, 2, 3};
    int n = v.size();
    insertionSort(v);
    for(int i=0; i<n; i++) {
        cout << v[i] << " \n"[i+1 == n];
    }

    return 0;
}