#include "Test_runner.h"

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}
TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << "(cerr) " << endl << fail_count << " tests failed. Terminate....";
        exit(69);
    }
}