// problem - calc_time_when_graph_is_connected
// TL-solution
// coder: wqrxssq

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

const int MAXN = 2e5;
int n, m;
vi g[MAXN];
pii e[MAXN];
unordered_map<int, int> q;
int used[MAXN];

void dfs(int v) {
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        q[id] = i;
    }

    for (int i = 0; i < m; i++) {
        int id_v, id_u;
        cin >> id_v >> id_u;
        int v = q[id_v];
        int u = q[id_u];
        e[i] = {v, u};
    }

    for (int i = 0; i < m; i++) {
        auto [v, u] = e[i];
        g[v].pb(u);
        g[u].pb(v);

        memset(used, 0, sizeof(int) * n);
        dfs(0);
        if (*min_element(used, used + n) == 1) {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << ":(\n";
}

int main() {
    fast_input;
    solve();
}
