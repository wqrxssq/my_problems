#include "testlib.h"

using ll = long long;

const int MAX_CNT_TESTS = 1e4;
const ll MAX_A = 1e18;
const ll MIN_A = 0;

// problem - dima-leap-years
// validator for multitests

// coder: wqrxssq

int main(int argc, char* argv[]) {
    // registerValidation(argc, argv); - открывает поток с тестами
    // inf - stream tests
    // readInt(l, r, "name") - read x and check l <= x <= r
    // readSpace - read space
    // readEoln - read end of line
    // readEof - read end of file
    registerValidation(argc, argv);
    int cnt_tests = inf.readInt(1, MAX_CNT_TESTS, "test_count");
    inf.readEoln();

    for (int i = 0; i < cnt_tests; i++) {
        // устоновим конкретный тест для валидатора
        setTestCase(i + 1);
        ll a = inf.readLong(0LL, MAX_A, "a");
        inf.readSpace();
        ll b = inf.readLong(0LL, MAX_A, "b");
        inf.readEoln();

        // проверим условие, что a <= b
        ensuref(a <= b, "a should be less or equal b!");
    }
    inf.readEof();
}