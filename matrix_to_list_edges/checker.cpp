// problem name - matrix to list of edges
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
    registerTestlibCmd(argc, argv);

    int m_jury = ans.readInt();
    int m_part = ouf.readInt();
    if (m_jury != m_part) {
        quitf(_wa, "The count of edges is wrong: expected = %d, found = %d", m_jury, m_part);
    }

    vector<pair<int, int>> e_jury;
    for (int i = 0; i < m_jury; i++) {
        int v = ans.readInt();
        int u = ans.readInt();
        e_jury.push_back({min(v, u), max(v, u)});
    }

    vector<pair<int, int>> e_part;
    for (int i = 0; i < m_jury; i++) {
        int v = ouf.readInt();
        int u = ouf.readInt();
        e_part.push_back({min(v, u), max(v, u)});
    }

    sort(e_jury.begin(), e_jury.end());
    sort(e_part.begin(), e_part.end());
    if (e_jury == e_part) {
        quitf(_ok, "The answer is correct!\n");
    } else {
        quitf(_wa, "The list of edges dont match!\n");
    }
}