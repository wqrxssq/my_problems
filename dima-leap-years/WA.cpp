#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <stack>
#include <cassert>
#include <iomanip>
#include <random>
#include <chrono>
#include <cstring>
#include <bitset>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector <int>;
using vvi = vector <vi>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vpii = vector <pii>;
const double PI = acos(-1);
const double EPS = 1e-6;
const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;

mt19937 rnd(static_cast<int>(chrono::steady_clock().now().time_since_epoch().count()));

#define all(_x) _x.begin(), _x.end()
#define rall(_x) _x.rbegin(), _x.rend()
#define pb push_back
#define ff first
#define ss second
#define sz(_x) (int)_x.size()
#define display(_x) for (auto el : _x) cout << el << ' '; cout << '\n'
#define cin_arr(_x) for (auto &el : _x) cin >> el;
#define fast_input ios_base::sync_with_stdio(0)
#define setpr(_x) cout << setprecision(_x) << fixed
#define debug(x) cout << __FUNCTION__ << ": " << #x " = " << (x) << endl

// problem - dima and leap years
// WA-solution
// coder: wqrxssq
// find first(naive->wrong) and last by formula

const ll MAXA = 1e18;

ll get_first(ll l, ll k) {
    return (l / k) * k;
}
ll get_last(ll l, ll k) {
    return (l / k) * k;
}

ll calc(ll l, ll r, ll k) {
    return max(get_last(r, k) / k - get_first(l, k) / k + 1, 0LL);
} 

void solve() {
    ll l, r;
    cin >> l >> r;
    ll ans1 = calc(l, r, 4);
    ll ans2 = calc(l, r, 4) - calc(l, r, 100) + calc(l, r, 400);
    cout << ans1 - ans2 << '\n';
}

int main() {
    fast_input;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        solve();
}
