#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> v, int n, int m, int maxAllowedPages);

int allocateBooks(vector<int> v, int n, int m);

int main() {
    /*-------------------- Description ---------------------

    Given N books , A[i] represent the number of pages in ith book.
    Task is to allocate books to M number of students so that :
    maximum no. of pages allocated to a student is minimum.
    --- Constraints ---
    1) Each book should be allocated to a student.
    2) Each student has to be allocated at least one book.
    3) Allotment should be in contiguous order.

    calculate and return that minimum possible number
    return -1 if a valid assignment is not possible.

    Total ways will be C(n-1, m-1) , for (n books and m students);

    Example : 
    arr = [2, 1, 3, 4],  N = 4,  M = 2;
    possible (s1, s2) pairs --> no. of pages of student 1 and 2;
    (2,8), (3,7), (6,4)
      |      |      |
      8      7      6 <-- this will be answer (minimum of maximum)
    
    Here total pages was 10, we will try to divide it equally among students
    
    If m>n --> NO possible way to do the allocation

    (min = 0) ------------------------------------ (max = sum of all pages)
    Ans is no. of pages and will lie in above range (which is sorted) :)
    Can apply binary search on this range :) (i.e. the range of number of pages)

    ### Approach ###
    take st, end . then calculate mid ( for the range of number of pages )
                mid
              /     \
           valid   invalid
          /             \
        left           right


    --------------------------------------------------------------*/

    vector<int> v = {2,1,3,4};
    int n = 4, m = 2;
    cout << allocateBooks(v, n, m) << endl;

    vector<int> v1 = {15, 17, 20};
    int n1=3, m1=2;
    cout << allocateBooks(v1, n1, m1) << endl;

    vector<int> v2 = {12, 34, 67, 90};
    int n2=4, m2=2;
    cout << allocateBooks(v2, n2, m2) << endl;

    vector<int> v3 = {15, 17, 20};
    int n3=3, m3=5;
    cout << allocateBooks(v3, n3, m3) << endl;

    vector<int> v4 = {22, 23, 67};
    int n4=3, m4=1;
    cout << allocateBooks(v4, n4, m4) << endl;

    return 0;
}

int allocateBooks(vector<int> v, int n, int m) {

    if(m > n) return -1;

    int st = 0, end = 0;
    for(auto val : v) end += val;

    int ans = -1;
    while(st <= end) {  // O( log(N) * n ) // N is the sum of pages;

        int mid = st + (end-st)/2;

        if( isValid(v, n, m, mid) ) { // means we can have a allocation with mid as maximum ==> then check for lower value.
            ans = mid;
            end = mid - 1;
        } else { // means we don't have this allocation (mid as maximum no. of pages) ==> check for some other max.
            st = mid + 1;
        }
    }

    return ans;
}

bool isValid(vector<int> v, int n, int m, int maxAllowedPages) {
    // this maxAllowedPages is mid only.
    // for mid to be valid
    // Every student must get lesser no. of pages than mid
    // max allowed pages is 'mid' .
    // give each student no. of pages less than mid
    // and get the required no. of student (it should be less than m)
    // we know that n <= m;

    int students = 1, pages = 0; // pages is the no. of pages at the current student

    for(int i=0; i<n; i++) {
        // edge case OR Trivial(or non-trivial) case :)
        if( v[i] > maxAllowedPages ) return false;

        if( pages + v[i] <= maxAllowedPages ) {
            pages += v[i];
        } else {
            students++;
            pages = v[i];
        }
    }
    
    // if students < m --> there exits ways in which all students can be allocated books (with satisfying all the constraints);
    // we have students < m <= n ; (students = m) is trivial :)
    // we can assign book such that every m students gets a book ;
    return (students <= m);
}
