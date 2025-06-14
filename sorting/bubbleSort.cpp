#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

// O(n^2)
void bubbleSort(vi& v) {
    // n-1 iterations ==> which has n-i-1 iteration to shift largest element to the end
    // ==> All n-1 (if they are at front) will be shifted to their correct position ;)
    int n = v.size();
    for(int i=0; i<n-1; i++) {
        bool isSwap = false;

        for(int j=0; j<n-i-1; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j+1], v[j]);
                isSwap = true;
            }
        }
        // if the array is already sorted then no swapping will occur, so return from there :)
        if(!isSwap) return;
    }
}

int main() {
    vi v = {4, 1, 5, 2, 3};
    int n = v.size();
    bubbleSort(v);
    for(int i=0; i<n; i++) {
        cout << v[i] << " \n"[i+1 == n];
    }

    return 0;
}