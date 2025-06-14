#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n^2)
int bruteForce(vector<int> v) {
    int n = v.size();
    for(int i : v) {
        int freq = 0;
        for(int j : v) {
            if(i == j) {
                freq++;
                if(freq > n/2) {
                    return i;
                }
            }
        }
    }
    return -1;
}

// Not the best but optimized than the BruteForce.
// O(n log(n) + n) --> O(nlogn) :)
int optimized(vector<int> v) {
    int n = v.size();
    sort(v.begin(), v.end());  // O(n*log(n))
    int freq = 0;
    int lastVal = v.front();
    for(auto val : v) {       // O(n)
        if(val == lastVal) {  // we can also check v[i] and v[i-1].
            freq++;
            if(freq > n/2) {
                return val;
            }
        } else {
            freq = 1;
        }
        lastVal = val;
    }
    return -1;

    // int freq = 1, ans = v[0];
    // for(int i=1; i<n; i++) {
    //     if(v[i] == v[i-1]) freq++;
    //     else {
    //         freq = 1;
    //         ans = v[i];
    //     }
    //     if(freq > n/2) return ans;
    // }
    // return ans;
}

// Moore's Voting algorithm. --> Most Optimized algorithm
// O(n)
int moore_algorithm(vector<int> v) {
    // 2,1,2,1,2,1,1
    // 1,2,1,2,1
    // 1,1,1,2
    // 2,1,1,1,2
    // 1,2,1,1,2,2,2
    // The majority element wil appear more than n/2 times, so the frequency will remain +ve for this
    // Which implies the number of times freq becomes zero will definitely become positive with the majority element as ans;
    // Very interesting , sound how it is working but it works.
    // TODO:
    // Write a formal proof of this algo ;

    // One intuition :
    // we already have more than n/2 occurrence of majority element so arrange it like follow
    // assume array as [a1,a2,...,an] and an be the majority element 
    // arrange it like this :
    // a1,an, a2,an, ...  , ai,an ; i<n/2 ; and there will atleast one more occurrence of an.
    // so now apply this algorithm as shown below
    // each time the freq will change from 0 to 1 and then to 0 and /
    // for the last occurrence the freq will become 1 and ans will become the majority element :).
    // and it doesn't depend on position of that last majority element .
    int freq = 0, ans = 0;
    for(int i=0; i<v.size(); i++) {
        // change the ans if the frequency becomes zero
        if(freq == 0) {
            ans = v[i];
        }
        //
        if(ans == v[i]) freq++;
        else freq--; // this is important part of moore's algorithm.
    }
    // Optional verification step. Time complexity will still be O(n).
    // int count = 0;
    // for(auto val : v) {
    //     if(val == ans) count++;
    // }
    // return (count > v.size()/2 ? ans : -1);
    return ans;
}

int main() {
    vector<int> v = {1,2,2,1,1,3,3,3,3,3,3,3};
    // cout << bruteForce(v) << endl;
    // cout << optimized(v) << endl;
    cout << moore_algorithm(v) << endl;
    
    return 0;
}
