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

// problem - dima and armor
// main-solution1 
// coder: wqrxssq
// simple dp

const int CNT_TYPES = 4;
tuple<int, int, int> q[CNT_TYPES];

void solve() {
    // init 
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < CNT_TYPES; i++) {
        auto &[a, b, k] = q[i]; 
        cin >> a >> b >> k;
    }
    vector <vll> dp(n + 1, vll(m + 1));

    // calc dp
    ll res = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int z = 0; z < CNT_TYPES; z++) {
                auto [a, b, k] = q[z];
                if (i - a >= 0 && j - b >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - a][j - b] + k);
                }
                res = max(res, dp[i][j]);
            }
        }
    }

    // print ans
    cout << res << '\n';
}

int main() {
    fast_input;
    #ifdef __APPLE__
    freopen("test3.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    #endif
    solve();
}
