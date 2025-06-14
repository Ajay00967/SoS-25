#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

// O(n) and O(1)
// There is a stl function as well : next_permutation(v.begin(), v.end()) 
void nextPermute(vi & v) {

    // next_permutation(v.begin(), v.end());

    int n = v.size();
    int pivot = -1;
    
    for(int i=n-2; i>=0; i--) {
        if(v[i] < v[i+1]) {
            pivot = i;
            break;
        }
    }

    if(pivot == -1) {
        // This means that the order is decreasing.
        // int i=0, j=n-1;
        // while(i<j) {
        //     swap(v[i++], v[j--]);
        // }
        reverse(v.begin(), v.end());
        return;
    }

    for(int i=n-1; i>pivot; i--) {
        if(v[i] > v[pivot]) { // right most value just bigger than that of at pivot :)
            swap(v[i], v[pivot]);
            break;
        }
    }
    // int i=pivot+1, j=n-1;
    // while(i<j) {
    //     swap(v[i++], v[j--]);
    // }
    reverse(v.begin()+pivot+1, v.end());

}

int main() {
    /*
    if A = [1,2,3] 
    then its next permutation will be 1,3,2 (lexicographically)
    some more examples : 
    1,2,3,6,5,4 --> 1,2,4,3,5,6
        |
    Here 3 is the pivot 
    because elements after that are already in decreasing order,
    i.e. we cannot make any bigger element using those element

    So this pivot is very important. 

    ====== Steps ====
    1) Find the pivot. (using a backward loop) 
    ==> 1,2,3,6,5,4 -> 3 is pivot
    2) Find the rightmost element > pivot. (To form the next number just bigger than that).
       and swap those two elements ( pivot and next bigger ).
    ==> 1,2,4,6,5,3 (notice that last three elements are still in decreasing order)
    3) Reverse the last p-1 digit (where p is the position of pivot from end) [ from pivot+1 to n-1 ]
    ==> 1,2,4,3,5,6

    */

    vi A = {1,2,3,6,5,4};

    nextPermute(A);

    for(auto a : A) cout << a << " ";
    cout << "\n";

    return 0;
}