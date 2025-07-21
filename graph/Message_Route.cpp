#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i, l, n) for(decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define fe(ds) for(auto x : ds)
#define ll long long
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define in(v,n) v.resize(n); for(auto &x : v) cin >> x;
#define out(v,n) f(i,0,n) cout << v[i] << " "; cout << endl
#define debug(x) cerr << #x << " is " << x << endl
#define yn(check) cout << (check ? "YES" : "NO") << "\n"
#define inp(type, ...) type __VA_ARGS__; read(__VA_ARGS__)
#define print(...) write(__VA_ARGS__)
#define minv(v) (*min_element(all(v)))
#define maxv(v) (*max_element(all(v)))
#define mini(v) (min_element(all(v))-(v).begin())
#define maxi(v) (max_element(all(v))-(v).begin())
#define sum(v) (accumulate(all(v), 0LL))
#define lb(v,x) (lower_bound(all(v), x))
#define ub(v,x) (upper_bound(all(v), x))
#define eqr(v,x) (equal_range(all(v), x))
#define lbs(s,x) (s.lower_bound(x))
#define ubs(s,x) (s.upper_bound(x))
#define ceiling(a,b) ((a+b-1)/b)
#define vec(a,n) vi a; in(a,n)

const ll MOD = 1e9 + 7;
const long double eps = 1e-9;

template<typename T>
void read(T& x) {
    cin >> x;
}

template<typename T, typename... Args>
void read(T& x, Args&... args) {
    cin >> x;
    read(args...);
}

template<typename T>
void write(T x) {
    cout << x << endl;
}

template<typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << " ";
    write(args...);
}

using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using pi = pair<ll,ll>;
using vpi = vector<pi>;
using si = set<ll>;
using usi = unordered_set<ll>;
using msi = multiset<ll>;
using mi = map<ll,ll>;
using umi = unordered_map<ll,ll>;

void solve() {
    inp(ll, n, m);
    vvi adj(n);
    f (i, 0, m) {
        inp(ll, a, b);
        a--, b--;
        adj[a].pb(b), adj[b].pb(a);
    }

    
}

bool multi = 0;

int main() {
    fastio;
    ll t = 1;
    if (multi) cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}