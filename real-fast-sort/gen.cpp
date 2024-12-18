// problem name - real-fast-sort
// generator
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
using namespace std;

const int MAXN = 1e8;
const uint32_t MIN_A = 0;
const uint32_t TEST_A = 10;
const uint32_t MAX_A = 4294967295;

void generate_small() {
    int n = rnd.next(5, 10);
    uint32_t x0 = rnd.next(MIN_A, TEST_A);
    uint32_t x1 = rnd.next(MIN_A, TEST_A);
    uint32_t a = rnd.next(MIN_A, TEST_A);
    uint32_t b = rnd.next(MIN_A, TEST_A);
    uint32_t c = rnd.next(MIN_A, TEST_A);

    println(n, x0, x1, a, b, c);
}

void generate_average() {
    int n = rnd.next(100000, 500000);

    uint32_t x0 = rnd.next(MIN_A, MAX_A);
    uint32_t x1 = rnd.next(MIN_A, MAX_A);
    uint32_t a = rnd.next(MIN_A, MAX_A);
    uint32_t b = rnd.next(MIN_A, MAX_A);
    uint32_t c = rnd.next(MIN_A, MAX_A);

    println(n, x0, x1, a, b, c);
}

void generate_big() {
    int n = MAXN;

    uint32_t x0 = rnd.next(MIN_A, MAX_A);
    uint32_t x1 = rnd.next(MIN_A, MAX_A);
    uint32_t a = rnd.next(MIN_A, MAX_A);
    uint32_t b = rnd.next(MIN_A, MAX_A);
    uint32_t c = rnd.next(MIN_A, MAX_A);

    println(n, x0, x1, a, b, c);
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