#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int C = 16;
const int MEM = (1 << C);
const int MASK = MEM - 1;

void fast_sort(vector<uint32_t>& a) {
    vector<uint32_t> a_copy = a;
    vector<int>cnt(MEM);

    for (uint32_t x : a) {
        cnt[x & MASK]++;
    }
    for (size_t i = 1; i < MEM; ++i) {
        cnt[i] += cnt[i - 1];
    }
    reverse(a.begin(), a.end());
    for (uint32_t x : a) {
        a_copy[--cnt[x & MASK]] = x;
    }
    a.swap(a_copy);

    fill(cnt.begin(), cnt.end(), 0);
    for (uint32_t x : a) {
        cnt[x >> C]++;
    }
    for (size_t i = 1; i < MEM; ++i) {
        cnt[i] += cnt[i - 1];
    }
    reverse(a.begin(), a.end());
    for (uint32_t x : a) {
        a_copy[--cnt[x >> C]] = x;
    }
    a.swap(a_copy);
}

uint32_t calc(vector<uint32_t>& a) {
    uint32_t ans = 0;
    for (uint32_t i = 0; i < a.size(); i++) {
        ans += a[i] * (i + 1);
    }
    return ans;
}

int main() {
#ifdef __APPLE__
    freopen("test1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    uint32_t x0, x1, a, b, c;
    cin >> n >> x0 >> x1 >> a >> b >> c;
    vector<uint32_t> temp(n);
    for (uint32_t &x : temp) {
        x = (a * x0 + b * x1 + c);
        x0 = x1;
        x1 = x;
    }

    // for (auto &x : temp) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    fast_sort(temp);

    // for (auto &x : temp) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    cout << calc(temp) << '\n';
}