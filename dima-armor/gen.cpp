// problem name - dima and armor
// generator
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif
#include <iostream>

using namespace std;

const int CNT_TYPES = 4;
const int MAX_MULTI = 2 * 1e6;
const int MIN_MULTI = 0;
const int MAX_A = 1e6;

void generate_small() {
    int n = rnd.next(90, 100);
    int m = rnd.next(90, 100);
    println(n, m);
    for (int i = 0; i < CNT_TYPES; i++) {
        int a = rnd.next(0, 20);
        int b = rnd.next(0, 20);
        while (!b) {
            b = rnd.next(0, 20);
        }
        int k = rnd.next(0, 100);
        println(a, b, k);
    }
}

void generate_average() {
    int n = rnd.next(900, 1000);
    int m = rnd.next(900, 1000);
    println(n, m);
    for (int i = 0; i < CNT_TYPES; i++) {
        int a = rnd.next(0, 200);
        int b = rnd.next(0, 200);
        while (!b) {
            b = rnd.next(0, 200);
        }
        int k = rnd.wnext(0, 100000, 50);
        println(a, b, k);
    }
}

void generate_small_only_n() {
    int n = rnd.wnext(10000, 2000000, 2000);
    int m = 0;
    println(n, m);
    for (int i = 0; i < CNT_TYPES; i++) {
        int a = rnd.next(1, 200);
        int b = rnd.wnext(0, 1, -5);
        int k = rnd.wnext(0, 15, 3);
        println(a, b, k);
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
        generate_small_only_n();
    return 0;
}