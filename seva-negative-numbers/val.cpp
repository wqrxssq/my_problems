#include "testlib.h"

const int MAX_INT = 1e9;
const int MIN_INT = -1e9;
const int MAX_CNT_TEST = 1e4;
const int MAX_SUM_N = 2e5;
const int MAX_N = 2e5;

// problem - fear-vasya
// validator for multitests

int main(int argc, char* argv[]) {
    // registerValidation(argc, argv); - открывает поток с тестами
    // inf - stream tests
    // readInt(l, r, "name") - read x and check l <= x <= r
    // readSpace - read space
    // readEoln - read end of line
    // readEof - read end of file
    registerValidation(argc, argv);
    int cnt_tests = inf.readInt(1, MAX_CNT_TEST, "test_count");
    inf.readEoln();
    int sum_n = 0;
    for (int i = 0; i < cnt_tests; i++) {
        // устоновим конкретный тест для валидатора
        setTestCase(i + 1);
        int n = inf.readInt(1, MAX_N, "n");
        inf.readEoln();

        // проверим условие, что сумма n по всем тестам <= 2e5
        sum_n += n;
        ensuref(sum_n <= MAX_SUM_N, "Sum of n is > 2e5");

        // считать n чисел и проверить каждое
        inf.readInts(n, MIN_INT, MAX_INT, "a[i]");
        inf.readEoln();
    }
    inf.readEof();
}