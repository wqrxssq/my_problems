#include "testlib.h"
#include <iostream>

using namespace std;

const int MAX_CNT_TESTS = 1e4;
const long long MIN_A = 0;
const long long AVERAGE_A = 1e9;
const long long MAX_A = 1e18;

void generate_many_small() {
    int t = rnd.wnext(100, MAX_CNT_TESTS, 200);
    println(t);
    for (int i = 0; i < t; i++) {
        long long a = rnd.wnext(MIN_A, 100LL, i / 100 + 1);
        long long b = rnd.wnext(MIN_A, 100LL, -(i / 100 + 1));
        if (a > b)
            swap(a, b);
        cout << a << ' ' << b << endl;
    }
}

void generate_many_average() {
    int t = rnd.wnext(100, MAX_CNT_TESTS, 200);
    println(t);
    for (int i = 0; i < t; i++) {
        long long a = rnd.wnext(MIN_A, AVERAGE_A, -3);
        long long b = rnd.wnext(MIN_A, AVERAGE_A, 3);
        if (a > b)
            swap(a, b);
        cout << a << ' ' << b << endl;
    }
}

void generate_many_big() {
    int t = rnd.wnext(100, MAX_CNT_TESTS, 300);
    println(t);
    for (int i = 0; i < t; i++) {
        long long a = rnd.wnext(MIN_A, MAX_A, -200);
        long long b = rnd.wnext(MIN_A, MAX_A, 200);
        if (a > b)
            swap(a, b);
        cout << a << ' ' << b << endl;
    }
}

void generate_many_full_random() {
    int t = rnd.wnext(100, MAX_CNT_TESTS, 300);
    println(t);
    for (int i = 0; i < t; i++) {
        long long a = rnd.next(MIN_A, MAX_A);
        long long b = rnd.next(MIN_A, MAX_A);
        if (a > b)
            swap(a, b);
        cout << a << ' ' << b << endl;
    }
}

void generate_full_tests() {
    int t = 1e4;
    println(t);
    for (int i = 0; i < t; i++) {
        cout << i << ' ' << MAX_A << endl;
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    // opt<type>("name") - reads -name= 
    // has_opt("name") - return 1 if -name= else 0

    int group_of_tests = opt<int>("g");
    int r = opt<int>("rnd");

    if (group_of_tests == 0)
        generate_many_small();
    else if (group_of_tests == 1) 
        generate_many_average();
    else if (group_of_tests == 2)
        generate_many_big();
    else if (group_of_tests == 3)
        generate_many_full_random();
    else 
        generate_full_tests();
    return 0;
}