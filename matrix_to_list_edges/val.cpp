// problem name - matrix to list of edges
// validator
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
#include <vector>
using namespace std;

const int MIN_N = 1;
const int MAX_N = 3000;

// registerValidation(argc, argv); - открывает поток с тестами
// inf - stream tests
// readInt(l, r, "name") - read x and check l <= x <= r
// readSpace - read space
// readEoln - read end of line
// readEof - read end of file
// ensuref - проверяет условие и если невыполнено то дает коментарий

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n;
    n = inf.readInt(MIN_N, MAX_N, "n");
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        vector<int> g;
        g = inf.readIntegers(n);
        inf.readEoln();
        ensuref(g[i] == 0, "Bad edges!\n");
    }
    inf.readEof();
}