#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

// O(N)
bool isPossible(vi& v, int c, int minAllowedDistance) {
    // sort(v.begin(), v.end()); // If we sort here, it will sort the array everytime times function runs
    int cows = 1, lastPosition = v[0];

    for(int i=1; i<v.size(); i++) {
        if(v[i] - lastPosition >= minAllowedDistance) {
            cows++;
            lastPosition = v[i];
        }

        if( cows == c ) return true;
    }

    return false;
}

// O(N * max(logN , log(Range)))
int largestMinimumDistance(vi& v, int cows) {

    sort(v.begin(), v.end()); // O(N logN)

    int n = v.size();
    if(cows > n) return -1;

    int st = 1; // when there are only 2 cows and placed on adjacent stall
    int end = v[n-1] - v[0];
    // 'end' will be when there are only 2 cows and placed on extremes;
    int ans = -1;

    while(st <= end) {  // O(log(range) * N)
        int mid = st + (end - st)/2;

        if(isPossible(v, cows, mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    /*
    Assign C cows to N stalls(where cow(s) is/are to kept) such that:
    min distance b/w them is largest possible
    return largest minimum distance;
    */

    vi v = {1,2,8,4,9};
    int c = 3;
    cout << largestMinimumDistance(v, c) << endl;


    return 0;
}
