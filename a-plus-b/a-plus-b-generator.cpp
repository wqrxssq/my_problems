#include "testlib.h"
#include <iostream>

using namespace std;

const int MAX_A = 1e9;
const int MIN_A = -1e9;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    // opt<type>("name") - reads -name= 
    // has_opt("name") - return 1 if -name= else 0

    // for random
    int n = opt<int>("n");

    // group of tests 
    int group_of_tests = opt<int>("g");

    if (group_of_tests == 0) {
        cout << rnd.next(0, 10) << " ";
        cout << rnd.next(0, 10) << endl;
    } else if (group_of_tests == 1) {
        cout << rnd.next(-100, 100) << " ";
        cout << rnd.next(-100, 100) << endl;
    } else {
        cout << rnd.next(MIN_A, MAX_A) << " ";
        cout << rnd.next(MIN_A, MAX_A) << endl;
    }
    return 0;
}