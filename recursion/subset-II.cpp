#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using svi = set<vi>;
using vvi = vector<vi>;

// my solution
// O(n * 2^n)
void getPowerSet(vi arr, vi & ans, int i, svi& powerSet) {
    sort(arr.begin(), arr.end());
    if(i == arr.size()) {
        // sort(ans.begin(), ans.end());
        // if(powerSet.find(ans) == powerSet.end()) {
        //     powerSet.insert(ans);
        // }
        // better to sort the array before so that the subset will be sorted too :)
        powerSet.insert(ans);
        return;
    }

    ans.push_back(arr[i]);
    getPowerSet(arr, ans, i+1, powerSet);

    ans.pop_back();
    getPowerSet(arr, ans, i+1, powerSet);
}

// O(n * 2^n)
void getSubSets(vi arr, vi & ans, int i, vvi& powerSet) {
    // if we exclude a element (then we already have included it in some branch of tree)
    // so then we will never include that again (if we have exclude it (not included))
    sort(arr.begin(), arr.end());

    if(i == arr.size()) {
        powerSet.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    getSubSets(arr, ans, i+1, powerSet);

    ans.pop_back();
    
    // skipping the same value if we have excluded it
    int idx = i+1;
    while(idx < arr.size() && arr[idx] == arr[idx-1]) idx++;

    getSubSets(arr, ans, idx, powerSet);
}

int main() {
    vi arr = {1,2,2};
    // Duplicates possible
    svi s;
    vi ans;

    // getPowerSet(arr, ans, 0, s);

    // vvi p(s.begin(), s.end());

    vvi p;
    getSubSets(arr, ans, 0, p);
    auto n=p.size();

    for(int i=0; i<n; i++) {
        cout << "{";
        int m = p[i].size();
        for(int j=0; j<m; j++) {
            cout << p[i][j] << ",}"[j+1 == m];
        }
        if(m==0) cout << "}";
        cout << endl;
    }
    
    return 0;
}