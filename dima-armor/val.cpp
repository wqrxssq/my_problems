#ifdef __APPLE__
    #include "../testlib/testlib.h"
#else
    #include "testlib.h"
#endif

const int CNT_TYPES = 4;
const int MAX_MULTI = 2 * 1e6;
const int MIN_MULTI = 0;
const int MAX_A = 1e6;

// problem - dima and armor
// validator for tests

// coder: wqrxssq

// registerValidation(argc, argv); - открывает поток с тестами
// inf - stream tests
// readInt(l, r, "name") - read x and check l <= x <= r
// readSpace - read space
// readEoln - read end of line
// readEof - read end of file
// ensuref - проверяет условие и если невыполнено то дает коментарий

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n, m;
    n = inf.readInt(MIN_MULTI, MAX_MULTI, "n");
    inf.readSpace();
    m = inf.readInt(MIN_MULTI, MAX_MULTI, "m");
    inf.readEoln();

    // 0 <= n * m <= 2 * 10^6 
    ensuref(1LL * n * m <= MAX_MULTI && 1LL * n * m >= MIN_MULTI, "n * m should be less or equal 2 * 10^6");

    for (int i = 0; i < CNT_TYPES; i++) {
        int a, b, k;
        a = inf.readInt(0, MAX_A, "a");
        inf.readSpace();
        b = inf.readInt(0, MAX_A, "b");
        inf.readSpace();
        inf.readInt(0, MAX_A, "k");
        inf.readEoln();

        // проверим условие, что a + b > 0
        ensuref(a + b > 0, "a + b should be greater than null!");
    }
    inf.readEof();
}