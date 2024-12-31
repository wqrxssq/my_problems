// problem - robots-delivery
// generator
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>

using namespace std;

const int MAX_M = 2e5;
const int MIN_M = 0;

const int MAX_N = 2e5;
const int MIN_N = 2;

const int MIN_Q = 1;
const int MAX_Q = 2e5;
const int AVERAGE_Q = 1000;

const int AVERAGE_N = 1000;
const int MAX_N_FOR_FULL_GRAPH = 632;

struct query {
    char c;
    int v, u;
};

void print_test(const int n, const int m, const int q, const vector<pair<int, int>> &e, const vector<query>& queries) {
    println(n, m, q);

    for (auto [v, u] : e) {
        println(v, u);
    }

    for (auto [c, v, u] : queries) {
        println(c, v, u);
    }
}

vector<pair<int, int>> generate_random_edges(int n, int m) {
    set<pair<int, int>> q_e;
    vector<pair<int, int>> e;

    while ((int)q_e.size() < m) {
        int v = rnd.next(1, n);
        int u = rnd.next(1, n);
        if (v == u || q_e.contains({v, u}) || q_e.contains({u, v})) {
            continue;
        } else {
            q_e.insert({v, u});
            e.push_back({v, u});
        }
    }
    return e;
}

vector<query> generate_random_queries(int n, int q) {
    vector<query> queries;

    for (int i = 0; i < q; i++) {
        int v = rnd.next(1, n);
        int u = rnd.next(1, n);
        queries.push_back({'?', v, u});
    }

    return queries;
}

void generate_small_graph() {
    int n = rnd.next(4, 8);
    int m = rnd.wnext(1, min((n * (n - 1)) / 2, 10), n / 3);
    int q = rnd.next(2, 4);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e = generate_random_edges(n, m);
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
}

void generate_average_graph() {
    int n = rnd.wnext(MIN_N, AVERAGE_N, 5);
    int m = rnd.next(MIN_M, min((n * (n - 1)) / 2, AVERAGE_N * 3));
    int q = rnd.wnext(MIN_Q, AVERAGE_Q, 5);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e = generate_random_edges(n, m);
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
}

void generate_empty_graph() {
    int n = rnd.wnext(MIN_N, MAX_N, 10);
    int m = 0;
    int q = rnd.wnext(MIN_Q, MAX_Q, 2);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e;
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
}

void generate_tree() {
    int n = rnd.wnext(MIN_N, MAX_N, 4);
    int m = n - 1;
    int q = rnd.wnext(MIN_Q, MAX_Q, 5);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e;
    for (int v = 2; v <= n; v++) {
        int p = rnd.next(1, v - 1);
        e.push_back({p, v});
        if (rnd.next(0, 1)) {
            swap(e.back().first, e.back().second);
        }
    }
    shuffle(e.begin(), e.end());
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
}

void generate_bad_bamboo() {
    int n = rnd.wnext(MIN_N, MAX_N, 10);
    int q = rnd.wnext(MIN_Q, MAX_Q, 10);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e;
    vector<int> perm = rnd.perm(n);
    for (int i = 0; i < n - 1; i++) {
        if (rnd.next(0, 1)) {
            e.push_back({perm[i] + 1, perm[i + 1] + 1});
        }
    }
    shuffle(e.begin(), e.end());

    int m = (int)e.size();
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
}

void generate_graph_with_a_lot_of_edges() {
    int n = rnd.wnext(MIN_N, MAX_N_FOR_FULL_GRAPH, 10);
    int q = rnd.wnext(MIN_Q, MAX_Q, 10);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rnd.next(0, 1)) {
                e.push_back({i + 1, j + 1});
                if (rnd.next(0, 1)) {
                    swap(e.back().first, e.back().second);
                }
            }
        }
    }
    shuffle(e.begin(), e.end());

    int m = (int)e.size();
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
}

void generate_full_graph() {
    int n = rnd.wnext(MIN_N, MAX_N_FOR_FULL_GRAPH, 5);
    int m = (n * (n - 1)) / 2;
    int q = rnd.wnext(MIN_Q, MAX_Q, 10);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            e.push_back({i + 1, j + 1});
            if (rnd.next(0, 1)) {
                swap(e.back().first, e.back().second);
            }
        }
    }
    shuffle(e.begin(), e.end());
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
}

void generate_big_graph() {
    int n = MAX_N;
    int m = MAX_M;
    int q = MAX_Q;
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [0, 2e5]");
    ensuref(q >= MIN_Q && q <= MAX_Q, "q should be [1, 2e5]");

    vector<pair<int, int>> e = generate_random_edges(n, m);
    ensuref((int)e.size() == m, "m should be same as size of E");

    vector<query> queries = generate_random_queries(n, q);
    ensuref((int)queries.size() == q, "q should be same as size of queries");

    print_test(n, m, q, e, queries);
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
        generate_graph_with_a_lot_of_edges();
    } else if (group_of_tests == 3) {
        generate_empty_graph();
    } else if (group_of_tests == 4) {
        generate_tree();
    } else if (group_of_tests == 5) {
        generate_bad_bamboo();
    } else if (group_of_tests == 6) {
        generate_full_graph();
    } else if (group_of_tests == 7) {
        generate_big_graph();
    } else {
        assert(0);
    }
    return 0;
}