// problem name - john_director
// checker
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// registerValidation(argc, argv); - открывает поток с тестами
// ans - jury stream
// ouf - participant stream
// inf - stream tests
// readInt(l, r, "name") - read x and check l <= x <= r
// readSpace - read space
// readEoln - read end of line
// readEof - read end of file
// ensuref - проверяет условие и если невыполнено то дает коментарий

const int MIN_N = 2;
const int MAX_N = 2e5;

const int MIN_M = 0;
const int MAX_M = 2e5;

void dfs(int v, vector<vector<int>>& g, vector<int>& used) {
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u, g, used);
        }
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int ans_jury = ans.readInt();
    int ans_part = ouf.readInt(0, MAX_M, "k");

    if (ans_jury != ans_part) {
        quitf(_wa, "Ans of jury and participant dont match!\n");
    }

    int n = inf.readInt();
    int m = inf.readInt();

    vector<vector<int>> g(n);
    vector<int> used(n);
    for (int i = 0; i < m; i++) {
        int v = inf.readInt();
        int u = inf.readInt();
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    for (int i = 0; i < ans_part; i++) {
        int v = ouf.readInt(1, n, "v");
        int u = ouf.readInt(1, n, "v");
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, g, used);

    if (*min_element(used.begin(), used.end()) == 1) {
        quitf(_ok, "The answer is correct!\n");
    } else {
        quitf(_wa, "The graph is not connected!\n");
    }
}