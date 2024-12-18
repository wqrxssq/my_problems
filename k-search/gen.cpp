// problem name - k-search
// generator
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
using namespace std;

const int MAXN = 1e5;
const int MAXQ = 2e5;
const int TESTVAL = 10;
const int MAXVAL = 1e9;
const int MINVAL = 0;

void generate_small() {
    const int N_MAX = 10;
    const int N_MIN = 3;

    int n = rnd.next(N_MIN, N_MAX);
    int q = rnd.next(N_MIN, N_MAX);
    println(n, q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(MINVAL, TESTVAL);
    }
    println(a);

    int left = MAXQ;
    for (int i = 0; i < q; i++) {
        int type;
        if (left) {
            type = rnd.next(0, 2);
        } else {
            type = rnd.next(0, 1);
        }
        int x, k;

        switch (type) {
        case 0:
            x = rnd.next(MINVAL, TESTVAL);
            println("+", x);
            a.push_back(x);
            break;
        case 1:
            println("-");
            a.pop_back();
            break;
        case 2:
            k = rnd.wnext(1, min(left, (int)a.size()), -3);
            println("?", k);
            left -= k;
            break;
        default:
            break;
        }
    }
}

void generate_average() {
    const int N_MAX = 2000;
    const int N_MIN = 1000;
    const int Q_MAX = 10000;
    const int Q_MIN = 2000;

    int n = rnd.next(N_MIN, N_MAX);
    int q = rnd.next(Q_MIN, Q_MAX);
    println(n, q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(MINVAL, MAXVAL);
    }
    println(a);

    int left = MAXQ;
    for (int i = 0; i < q; i++) {
        int type;
        if (left) {
            type = rnd.next(0, 2);
        } else {
            type = rnd.next(0, 1);
        }

        int x, k;

        switch (type) {
        case 0:
            x = rnd.next(MINVAL, TESTVAL);
            println("+", x);
            a.push_back(x);
            break;
        case 1:
            println("-");
            a.pop_back();
            break;
        case 2:
            k = rnd.wnext(1, min(left, (int)a.size()), -3);
            println("?", k);
            left -= k;
            break;
        default:
            break;
        }
    }
}

void generate_big_with_small_k() {
    int n = MAXN;
    int q = MAXQ;

    println(n, q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(MINVAL, MAXVAL);
    }
    println(a);

    int left = MAXQ;
    for (int i = 0; i < q; i++) {
        int type;
        if (left) {
            type = rnd.next(0, 2);
        } else {
            type = rnd.next(0, 1);
        }
        int x, k;

        switch (type) {
        case 0:
            x = rnd.next(MINVAL, TESTVAL);
            println("+", x);
            a.push_back(x);
            break;
        case 1:
            println("-");
            a.pop_back();
            break;
        case 2:
            k = rnd.next(1, min(left, min((int)a.size(), 10)));
            println("?", k);
            left -= k;
            break;
        default:
            break;
        }
    }
}

void generate_big_with_big_k() {
    int n = MAXN;
    int q = MAXQ;

    println(n, q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(MINVAL, MAXVAL);
    }
    println(a);

    int left = MAXQ;
    for (int i = 0; i < q; i++) {
        int type;
        if (left) {
            type = rnd.next(0, 2);
        } else {
            type = rnd.next(0, 1);
        }
        int x, k;

        switch (type) {
        case 0:
            x = rnd.next(MINVAL, TESTVAL);
            println("+", x);
            a.push_back(x);
            break;
        case 1:
            println("-");
            a.pop_back();
            break;
        case 2:
            k = rnd.next(1, min(left, (int)a.size()));
            println("?", k);
            left -= k;
            break;
        default:
            break;
        }
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
        generate_big_with_small_k();
    else if (group_of_tests == 3) {
        generate_big_with_big_k();
    }
    return 0;
}