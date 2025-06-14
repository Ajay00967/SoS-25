#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

void merge(vi & A, int m, vi & B, int n) {
    // A has m valid element and total m+n space :)

    /*
    O(m*n)
    for(int i=0; i<n; i++) {
        int curr = B[i];
        int prev = m-1+i;
        while(prev >= 0 && A[prev] >= curr) {
            A[prev+1] = A[prev];
            prev--;
        }
        A[prev+1] = curr;
    }
    */

    /*
    O(m+n) and O(m+n)
    int i=0, j=0;
    vi c;
    while(i<m && j<n) {
        if(A[i] > B[j]) {
            c.push_back(B[j++]);
        } else {
            c.push_back(A[i++]);
        }
    }
    while(i<m) {
        c.push_back(A[i++]);
    }
    while(j<n) {
        c.push_back(B[j++]);
    }
    for(int i=0; i<m+n; i++) {
        A[i] =  c[i];
    }
    */

    // O(m+n) and O(1)
    int i=m-1, j=n-1; // i for A and j for B;
    int idx = m+n-1;
    while(i>=0 && j>=0) {
        if(A[i] > B[j]) {
            A[idx--] = A[i--];
        } else {
            A[idx--] = B[j--];
        }
    }
    while(j>=0) {
        A[idx--] = B[j--];
    }
    // Here no need to check for i because if j is 0 => B is placed correct so automatically A will also be in its correct position :)
}

int main() {
    // Given two sorted array , merge them into the first one
    // size of first is m , and that of second is n
    // capacity of first array is m+n for storing the rest of n values of B
    vi A = {1,2,3,0,0,0};
    vi B = {2,5,6};
    int m=3, n=3;

    merge(A, m, B, n);

    for(auto el : A) cout << el << " ";
    cout << endl;

    return 0;
}