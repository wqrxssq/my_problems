#include <iostream>
#include <vector>
#include <cstdint>
#include <math.h>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
const double PI = acos(-1);
const double EPS = 1e-6;
const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
 
mt19937 rnd(static_cast<unsigned int>(chrono::steady_clock().now().time_since_epoch().count()));
 
#define all(_x) _x.begin(), _x.end()
#define rall(_x) _x.rbegin(), _x.rend()
#define pb push_back
#define ff first
#define ss second
#define sz(_x) (int)_x.size()
#define display(_x)        \
    for (auto el : _x)     \
        cout << el << ' '; \
    cout << '\n'
#define cin_arr(_x)     \
    for (auto& el : _x) \
        cin >> el;
#define fast_input ios_base::sync_with_stdio(0); cin.tie(0)
#define setpr(_x) cout << setprecision(_x) << fixed
#define debug(x) cout << __FUNCTION__ << ": " << #x " = " << (x) << endl

uint32_t calc(vector<uint32_t>& a) {
    uint32_t ans = 0;
    for (uint32_t i = 0; i < a.size(); i++) {
        ans += a[i] * (i + 1);
    }
    return ans;
}

int main() {
    fast_input;

    int n;
    uint32_t x0, x1, a, b, c;
    cin >> n >> x0 >> x1 >> a >> b >> c;
    vector<uint32_t> temp(n);
    for (uint32_t &x : temp) {
        x = (a * x0 + b * x1 + c);
        x0 = x1;
        x1 = x;
    }

    sort(all(temp));

    cout << calc(temp) << '\n';
}