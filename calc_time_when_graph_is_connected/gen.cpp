// problem - calc_time_when_graph_is_connected
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
const int MIN_M = 1;

const int MAX_N = 2e5;
const int MIN_N = 2;

const int AVERAGE_N = 1000;
const int MAX_N_FOR_FULL_GRAPH = 632;

const int MIN_ID = 1;
const int MAX_ID = 1e9;

void print_test(const int n, const int m, const vector<int>& ids, const vector<pair<int, int>> &e) {
    println(n, m);

    // extra
    println(ids);

    for (auto [v, u] : e) {
        println(v, u);
    }
}

vector<int> generate_ids(int type, int n) {
    vector<int> ids;
    if (type == 0) {
        for (int i = 0; i < n; i++) {
            ids.push_back(i + 1);
        }
    } else if (type == 1) {
        unordered_set<int> q_id;
        while ((int)q_id.size() < n) {
            int id = rnd.next(MIN_ID, MAX_ID);
            if (q_id.contains(id)) {
                continue;
            } else {
                q_id.insert(id);
                ids.push_back(id);
            }
        }
    } else {
        assert(0);
    }
    return ids;
}

vector<pair<int, int>> generate_random_edges(int n, int m, vector<int>& ids) {
    set<pair<int, int>> q_e;
    vector<pair<int, int>> e;

    while ((int)q_e.size() < m) {
        int v = rnd.next(1, n);
        int u = rnd.next(1, n);
        if (v == u || q_e.contains({v, u}) || q_e.contains({u, v})) {
            continue;
        } else {
            q_e.insert({v, u});
            e.push_back({ids[v - 1], ids[u - 1]});
        }
    }
    return e;
}

void generate_small_graph() {
    int n = rnd.next(4, 8);
    int m = rnd.wnext(1, min((n * (n - 1)) / 2, 10), n / 3);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [1, 2e5]");

    vector<int> ids = generate_ids(0, n);
    ensuref((int)ids.size() == n, "n should be same as size of ids");

    vector<pair<int, int>> e = generate_random_edges(n, m, ids);
    ensuref((int)e.size() == m, "m should be same as size of E");

    print_test(n, m, ids, e);
}

void generate_average_graph() {
    int n = rnd.wnext(MIN_N, AVERAGE_N, 4);
    int m = rnd.wnext(MIN_M, min((n * (n - 1)) / 2, AVERAGE_N * 4), 10);
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [1, 2e5]");

    vector<int> ids = generate_ids(1, n);
    ensuref((int)ids.size() == n, "n should be same as size of ids");

    vector<pair<int, int>> e = generate_random_edges(n, m, ids);
    ensuref((int)e.size() == m, "m should be same as size of E");

    print_test(n, m, ids, e);
}

void generate_tree() {
    int n = rnd.wnext(MIN_N, MAX_N, 4);
    int m = n - 1;
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [1, 2e5]");

    vector<int> ids = generate_ids(1, n);
    ensuref((int)ids.size() == n, "n should be same as size of ids");

    vector<pair<int, int>> e;
    for (int v = 2; v <= n; v++) {
        int p = rnd.next(1, v - 1);
        e.push_back({ids[p - 1], ids[v - 1]});
    }
    shuffle(e.begin(), e.end());
    ensuref((int)e.size() == m, "m should be same as size of E");

    print_test(n, m, ids, e);
}

void generate_bamboo() {
    int n = MAX_N;
    int m = n - 1;
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [1, 2e5]");

    vector<int> ids = generate_ids(1, n);
    ensuref((int)ids.size() == n, "n should be same as size of ids");

    vector<pair<int, int>> e;
    vector<int> perm = rnd.perm(n);
    for (int i = 0; i < n - 1; i++) {
        e.push_back({ids[perm[i]], ids[perm[i + 1]]});
    }
    shuffle(e.begin(), e.end());
    ensuref((int)e.size() == m, "m should be same as size of E");

    print_test(n, m, ids, e);
}

void generate_graph_with_a_lot_of_edges() {
    int n = rnd.wnext(MIN_N, MAX_N_FOR_FULL_GRAPH, 10);

    vector<int> ids = generate_ids(1, n);
    ensuref((int)ids.size() == n, "n should be same as size of ids");

    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rnd.next(0, 1)) {
                e.push_back({ids[i], ids[j]});
            }
        }
    }
    shuffle(e.begin(), e.end());

    int m = (int)e.size();
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [1, 2e5]");

    print_test(n, m, ids, e);
}

void generate_full_graph() {
    int n = rnd.wnext(MIN_N, MAX_N_FOR_FULL_GRAPH, 5);
    int m = (n * (n - 1)) / 2;
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [1, 2e5]");

    vector<int> ids = generate_ids(1, n);
    ensuref((int)ids.size() == n, "n should be same as size of ids");

    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            e.push_back({ids[i], ids[j]});
        }
    }
    shuffle(e.begin(), e.end());
    ensuref((int)e.size() == m, "m should be same as size of E");

    print_test(n, m, ids, e);
}

void generate_big_graph() {
    int n = rnd.wnext(MAX_N / 6, MAX_N / 2, -5);
    int m = MAX_M;
    ensuref(n >= MIN_N && n <= MAX_N, "n should be [2, 2e5]");
    ensuref(m >= MIN_M && m <= MAX_M, "m should be [1, 2e5]");

    vector<int> ids = generate_ids(1, n);
    ensuref((int)ids.size() == n, "n should be same as size of ids");

    vector<pair<int, int>> e = generate_random_edges(n, m, ids);
    ensuref((int)e.size() == m, "m should be same as size of E");

    print_test(n, m, ids, e);
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
        generate_tree();
    } else if (group_of_tests == 4) {
        generate_bamboo();
    } else if (group_of_tests == 5) {
        generate_full_graph();
    } else if (group_of_tests == 6) {
        generate_big_graph();
    } else {
        assert(0);
    }
    return 0;
}