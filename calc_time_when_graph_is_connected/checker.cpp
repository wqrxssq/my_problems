// problem name - calc_time_when_graph_is_connected
// checker
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
#include <vector>
using namespace std;

// registerValidation(argc, argv); - открывает поток с тестами
// inf - stream tests
// readInt(l, r, "name") - read x and check l <= x <= r
// readSpace - read space
// readEoln - read end of line
// readEof - read end of file
// ensuref - проверяет условие и если невыполнено то дает коментарий

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    string ans_jury = ans.readString();
    string ans_part = ouf.readString();
    if (ans_jury == ans_part) {
        quitf(_ok, "The answer is correct!\n");
    } else {
        quitf(_wa, "The string doesnot match!\n");
    }
}