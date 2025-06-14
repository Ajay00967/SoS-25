#include <iostream>
#include <vector>
using namespace std;

pair<int,int> pairSum(vector<int> v, int target) {
    int n = v.size();
    int i = 0, j = n-1;

    while(i<j) {
        int sum = v[i] + v[j];
        if(sum == target) return {i,j};
        else if(sum < target) i++;
        else j--;
    }
    return {-1,-1};
}

int main() {
    // given an sorted array in ascending order
    // return a pair with sum same as the target sum;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 11, 13};
    // here if more than one such pair exist then print the first one. like the one with first element coming first.
    int target = 13;

    auto p = pairSum(v, target);
    cout << p.first << "," << p.second << endl;

    return 0;
}