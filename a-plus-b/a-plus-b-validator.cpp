#include "testlib.h"

const int MAX_INT = 1e9;
const int MIN_INT = -1e9;

int main(int argc, char* argv[]) {
    // registerValidation(argc, argv); - открывает поток с тестами
    // inf - stream tests
    // readInt(l, r, "name") - read x and check l <= x <= r
    // readSpace - read space
    // readEoln - read end of line
    // readEof - read end of file
    registerValidation(argc, argv);
    inf.readInt(MIN_INT, MAX_INT, "a");
    inf.readSpace();
    inf.readInt(MIN_INT, MAX_INT, "a");
    inf.readEoln();
    inf.readEof();
}