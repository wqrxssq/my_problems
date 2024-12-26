// problem name - list_edges_to_list_adj_ver
// checker
// coder: wqrxssq

#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// registerValidation(argc, argv); - открывает поток с тестами
// ans - jury stream
// ouf - participant stream
// inf - stream tests
// readInt(l, r, "name") - read x and check l <= x <= r
// readSpace - read space
// readEoln - read end of line
// readEof - read end of file
// ensuref - проверяет условие и если невыполнено то дает коментарий

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();

    vector<pair<int, int>> e_jury;
    for (int v = 0; v < n; v++) {
        int n_jury = ans.readInt();
        int n_part = ouf.readInt();

        if (n_jury != n_part) {
            quitf(_wa, "The list of adj verticies dont match!\n");
        }

        vector<int> adj_jury = ans.readIntegers(n_jury);
        vector<int> adj_part = ouf.readIntegers(n_jury);

        sort(adj_jury.begin(), adj_jury.end());
        sort(adj_part.begin(), adj_part.end());

        if (adj_jury != adj_part) {
            quitf(_wa, "The list of adj verticies dont match!\n");
        }
    }
    quitf(_ok, "The answer is correct!\n");
}