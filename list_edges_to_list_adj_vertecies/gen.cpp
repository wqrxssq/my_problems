// problem - list_edges_to_list_adj_ver
// generator
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
using namespace std;

const int MAXM = 1e5;
const int MINM = 0;
const int MAXN = 1e5;
const int MINN = 1;
const int AVERAGEN = 1000;
const int MAXN_FOR_FULL_GRAPH = 447;

void print_e(const vector<pair<int, int>> &e) {
    for (auto [v, u] : e) {
        println(v, u);
    }
}

void generate_small_graph() {
    int n = rnd.next(3, 5);
    int m = rnd.next(1, min((n * (n - 1)) / 2, 10));
    ensuref(n >= MINN && n <= MAXN, "n should be [1, 10^5]");
    ensuref(m >= MINM && m <= MAXM, "m should be [0, 10^5]");

    vector<pair<int, int>> e;

    println(n, m);
    for (int i = 0; i < m; i++) {
        int v = rnd.next(MINN, n);
        int u = rnd.next(MINN, n);
        if (u == v) {
            u++;
            if (u == n + 1) {
                u = 1;
            }
        }
        e.push_back({v, u});
    }

    ensuref((int)e.size() == m, "m should be same as size of E");
    print_e(e);
}

void generate_average_graph() {
    int n = rnd.wnext(MINN, AVERAGEN, 10);
    int m = rnd.next(MINM, min((n * (n - 1)) / 2, AVERAGEN * 10));
    ensuref(n >= MINN && n <= MAXN, "n should be [1, 10^5]");
    ensuref(m >= MINM && m <= MAXM, "m should be [0, 10^5]");

    vector<pair<int, int>> e;

    println(n, m);
    for (int i = 0; i < m; i++) {
        int v = rnd.next(MINN, n);
        int u = rnd.next(MINN, n);
        if (u == v) {
            u++;
            if (u == n + 1) {
                u = 1;
            }
        }
        e.push_back({v, u});
    }

    ensuref((int)e.size() == m, "m should be same as size of E");
    print_e(e);
}

void generate_tree() {
    int n = rnd.next(MINN, MAXN);
    int m = n - 1;
    ensuref(n >= MINN && n <= MAXN, "n should be [1, 10^5]");
    ensuref(m >= MINM && m <= MAXM, "m should be [0, 10^5]");

    vector<pair<int, int>> e;

    println(n, m);
    for (int v = 2; v <= n; v++) {
        int p = rnd.next(MINN, v - 1);
        e.push_back({p, v});
    }

    ensuref((int)e.size() == m, "m should be same as size of E");
    print_e(e);
}

void generate_bamboo() {
    int n = rnd.wnext(MINN, MAXN, 10);
    int m = n - 1;
    ensuref(n >= MINN && n <= MAXN, "n should be [1, 10^5]");
    ensuref(m >= MINM && m <= MAXM, "m should be [0, 10^5]");

    vector<pair<int, int>> e;

    println(n, m);
    vector<int> perm = rnd.perm(n);
    for (int i = 0; i < n - 1; i++) {
        e.push_back({perm[i] + 1, perm[i + 1] + 1});
    }

    shuffle(e.begin(), e.end());

    ensuref((int)e.size() == m, "m should be same as size of E");
    print_e(e);
}

void generate_full_graph() {
    int n = rnd.wnext(MINN, MAXN_FOR_FULL_GRAPH, 5);
    int m = (n * (n - 1)) / 2;
    ensuref(n >= MINN && n <= MAXN, "n should be [1, 10^5]");
    ensuref(m >= MINM && m <= MAXM, "m should be [0, 10^5]");

    vector<pair<int, int>> e;

    println(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            e.push_back({i + 1, j + 1});
        }
    }

    shuffle(e.begin(), e.end());

    ensuref((int)e.size() == m, "m should be same as size of E");
    print_e(e);
}

void generate_big_graph() {
    int n = MAXN;
    int m = rnd.wnext(MINM, MAXM, 50);
    ensuref(n >= MINN && n <= MAXN, "n should be [1, 10^5]");
    ensuref(m >= MINM && m <= MAXM, "m should be [0, 10^5]");

    vector<pair<int, int>> e;

    println(n, m);
    for (int i = 0; i < m; i++) {
        int v = rnd.next(MINN, n);
        int u = rnd.next(MINN, n);
        if (u == v) {
            u++;
            if (u == n + 1) {
                u = 1;
            }
        }
        e.push_back({v, u});
    }

    ensuref((int)e.size() == m, "m should be same as size of E");
    print_e(e);
}

void generate_empty_graph() {
    int n = rnd.wnext(MINN, MAXN, 5);
    int m = 0;
    ensuref(n >= MINN && n <= MAXN, "n should be [1, 10^5]");
    ensuref(m >= MINM && m <= MAXM, "m should be [0, 10^5]");

    println(n, m);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    // opt<type>("name") - reads -name= 
    // has_opt("name") - return 1 if -name= else 0

    int group_of_tests = opt<int>("g");
    int r = opt<int>("rnd");

    if (group_of_tests == 0) {
        generate_small_graph();
    } else if (group_of_tests == 1) {
        generate_average_graph();
    } else if (group_of_tests == 2) {
        generate_tree();
    } else if (group_of_tests == 3) {
        generate_bamboo();
    } else if (group_of_tests == 4) {
        generate_full_graph();
    } else if (group_of_tests == 5) {
        generate_big_graph();
    } else {
        generate_empty_graph();
    }
    return 0;
}