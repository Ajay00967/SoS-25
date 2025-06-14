#include <iostream>
#include <vector>
using namespace std;

// O(n)
bool isPossible(vector<int> v, int m, int maxAllowedLength) { // maxAllowedLength OR maxAllowedTime ==> same thing
    int painters = 1, length = 0;

    for(int i=0; i<v.size(); i++) {
        if(v[i] > maxAllowedLength) return false;

        if( length + v[i] <= maxAllowedLength ) { // check for current painter
            length += v[i];
        } else {  // assign a new painter
            painters++;  // this is possible because of contiguous manner of assignment :)
            length = v[i];
        }
    }
    return ( painters <= m );
}

// O( n * log(sum) )
int minimumTime(vector<int> v, int m) {

    int n = v.size();
    if(n < m) return -1;

    int st=0, end=0;
    for(auto i : v) {
        end += i; // end is the total length of the boards :)
        st = max(st, i); // st is max of all board length that will be min time to paint;
                         // this is the hypothetical case when m = n, i.e. we have a painter for every board :)
    }

    int ans = -1;

    while(st <= end) {
        int mid = st + (end - st)/2;

        if( isPossible(v, m, mid) ) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    /*
    Given are N boards, length of each given in form of a array;
    M painters such that each painters takes 1 unit of time to paint 1 unit of board.
    The task is to find the minimum time to paint all boards under the constraints 
    ===> that any painter will only paint continuous section of the boards.abort

    This is a variation of book allocation problem :)
    */

    vector<int> v = {40, 30, 10, 20};
    int m = 2;
    cout << minimumTime(v,m) << endl;

    return 0;
}