#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

const int MAX_A = 1e9;
const int MIN_A = -1e9;

void generate_many_small() {
    int t = 1e4;
    println(t);
    for (int i = 0; i < t; i++) {
        int n = rnd.wnext(1, 10, 4);
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = rnd.next(-10, 10);
        }
        println(n);
        println(a);
    }
}

void generate_many_average() {
    int t = 100;
    println(t);
    for (int i = 0; i < t; i++) {
        int n = rnd.wnext(100, 2000, 20);
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = rnd.next(-10, 10);
        }
        println(n);
        println(a);
    }
}

void generate_few_big() {
    int t = rnd.next(2, 5);
    println(t);
    for (int i = 0; i < t; i++) {
        int n = rnd.wnext(100, 40000, 50);
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = rnd.next(MIN_A, MAX_A);
        }
        println(n);
        println(a);
    }
}

void generate_one_big() {
    println(1);
    int n = rnd.wnext(150000, 200000, 20);
    vector<int> a(n);
    for (int j = 0; j < n; j++) {
        a[j] = rnd.next(-10, 10);
    }
    println(n);
    println(a);
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
        generate_few_big();
    else
        generate_one_big();
    return 0;
}