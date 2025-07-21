#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7; 
const ll N = 1e6 + 5;

int main() {
    ll n;
    cin >> n;

    vector<ll> ways(N, 0);
    ways[0] = 1;
    
    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<7; j++) {
            if(i >= j) {
                ways[i] += ways[i-j];
                ways[i] %= mod;
            }
        }
    }
    cout << ways[n] << endl;

    return 0;
}