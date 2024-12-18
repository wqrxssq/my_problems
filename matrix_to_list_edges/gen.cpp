// problem name - matrix to list of edges
// generator
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
using namespace std;

const int MAXN = 3000;

void generate_small() {
    int n = rnd.next(3, 10);
    ensuref(n >= 1 && n <= MAXN, "n should be [1, 5000]");
    vector<vector<int>> g(n, vector<int>(n));

    println(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g[i][j] = rnd.next(0, 1);
            g[j][i] = g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        println(g[i]);
    }
}

void generate_average() {
    int n = rnd.next(1000, 3000);
    ensuref(n >= 1 && n <= MAXN, "n should be [1, 5000]");
    vector<vector<int>> g(n, vector<int>(n));

    println(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g[i][j] = rnd.next(0, 1);
            g[j][i] = g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        println(g[i]);
    }
}

void generate_big() {
    int n = MAXN;
    ensuref(n >= 1 && n <= MAXN, "n should be [1, 5000]");
    vector<vector<int>> g(n, vector<int>(n));

    println(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g[i][j] = rnd.next(0, 1);
            g[j][i] = g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        println(g[i]);
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    // opt<type>("name") - reads -name= 
    // has_opt("name") - return 1 if -name= else 0

    int group_of_tests = opt<int>("g");
    int r = opt<int>("rnd");

    if (group_of_tests == 0)
        generate_small();
    else if (group_of_tests == 1) 
        generate_average();
    else if (group_of_tests == 2)
        generate_big();
    return 0;
}