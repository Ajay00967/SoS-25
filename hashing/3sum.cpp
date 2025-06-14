#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

// O(n^3 * log(unique triplets)) & O(unique triplets)
vector<vi> bruteForce(vi arr) {
    int n = arr.size();
    vector<vi> ans;
    set<vector<int>> s;

    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                if(arr[i]+arr[j]+arr[k] == 0) {
                    vi temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());

                    if(s.find(temp) == s.end()) {
                        s.insert(temp);
                        ans.push_back(temp);
                    }
                    // ans.push_back({i, j, k});
                }
            }
        }
    }
    return ans;
}

// O(n^2 * log(unique triplets)) & O(unique triples + n)
vector<vi> better(vi arr) {
    // we will find the first and second val of the triplet and for the third val we'll use hashing
    // a + b + c == 0
    // c == -(a + b)

    int n = arr.size();
    set<vector<int>> unique; 

    for(int i=0; i<n; i++) {
        set<int> s; // like a different set of all of first values, which will store the second values
        // other than the first loop this is a 2sum problem;
        // this set s will contribute to the space complexity O(n)
        int tar = -arr[i];

        for(int j=i+1; j<n; j++) {
            int c = tar - arr[j];

            if(s.find(c) != s.end()) {
                vi temp = {arr[i], arr[j], c};
                sort(temp.begin(), temp.end());

                // if(unique.find(temp) == unique.end()) {
                //     unique.insert(temp);
                //     ans.push_back(temp);
                // }
                // no need to check just insert , because the set will not contain any duplicates

                unique.insert(temp);
            }

            s.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(unique.begin(), unique.end());

    return ans;
}

// O(n^2) & O(unique Triplet)
vector<vi> optimal(vi arr) {
    // sort the array 
    // use the 2-pointer approach
    // fix a idx i and then apply 2-pointer on remaining array
    /*
    e.g:
    [-1, 0, 1, 2, -1, -4]
    after sorting : [-4, -1, -1, 0, 1, 2]

    few edge case/repeating case :
    1) If two consecutive value of arr[i] are same ==> don't need to consider
    2) If a triplet found -> push the triplet in ans and j++, k--
        but it is possible the next value at j is same as the previous one
        then reach at that point until next j is different :)
    */
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {

        if(i && arr[i] == arr[i-1]) continue;

        int j=i+1, k=n-1;

        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if(sum == 0) {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++, k--;

                while(j < k && arr[j] == arr[j-1]) j++;

            } else if(sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    return ans;
}

int main() {
    // LeetCode : 15
    // given an array find 3 numbers such that sum of those is 0
    // find all such triplet whose sum is 0

    vi arr = {-1, 0, 1, 2, -1, 4};
    // [[-1,0,1], [-1,-1,2]] <-- possible triplets

    auto v = optimal(arr);
    for(auto triplet : v) {
        for(auto val : triplet) cout << val << " ";
        cout << endl;
    }
    

    return 0;
}