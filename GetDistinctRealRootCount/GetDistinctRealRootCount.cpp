#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception & e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};
int GetDis(const int& a, const int& b, const int& c) {
    return (pow(b, 2) - (4 * a * c));
}
vector<int> Solution(const int& a, const int& b, const int& c) {
    vector<int>res;
    res.resize(0);
    int D = GetDis(a, b, c);
    if (a == 0 && b != 0) {
        res.push_back((-1.0 * c) / (b));
        return res;
    }
    if (a == 0 && b == 0) {
        return res;
    }

    if (D > 0) {
        res.push_back((-1.0 * b - sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a));
        res.push_back((-1.0 * b + sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a));
    }
    else if (D == 0) res.push_back((-1.0 * b) / (2.0 * a));
    else res.resize(0);
    return res;
}
int GetDistinctRealRootCount(double a, double b, double c) {
    vector<int>x = Solution(a, b, c);
    return x.size();
}

void TestDis() {
    AssertEqual(GetDis(0, 1, 1), 1, " 011 ");
    AssertEqual(GetDis(1, 0, 1), -4, " 101 ");
    AssertEqual(GetDis(1, 1, 0), 1, " 110 ");
    AssertEqual(GetDis(0, 0, 1), 0, " 001 ");
    AssertEqual(GetDis(1, 0, 0), 0, " 100 ");
    AssertEqual(GetDis(0, 1, 0), 1, " 010 ");
}

void TestDistinctRealRootCount() {
    AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, " 011 ");//
    AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, " 101 ");
    AssertEqual(GetDistinctRealRootCount(1, 1, 0), 2, " 110 ");
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, " 001 ");
    AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, " 100 ");
    AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, " 010 ");
}

void EXECUTE() {
    TestRunner runner;
    runner.RunTest(TestDis, "TestDis");
    runner.RunTest(TestDistinctRealRootCount, "TestDistinctRealRootCount");
}

int main() {
    EXECUTE();

    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << " :" << GetDistinctRealRootCount(a, b, c) << endl;
    }
    return 0;
}
/*
//add
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception & e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};
double GetDis(const int& a, const int& b, const int& c) {
    return (pow(b, 2.0) - (4.0 * a * c));
}
vector<double> Solution(const int& a, const int& b, const int& c) {
    vector<double>res;
    res.resize(0);
    double D = GetDis(a, b, c);
    if (a == 0 && b != 0) {
        res.push_back((-1.0 * c) / (b));
        return res;
    }
    if (a == 0 && b == 0) {
        return res;
    }

    if (D > 0.0) {
        res.push_back((-1.0 * b - sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a));
        res.push_back((-1.0 * b + sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a));
    }
    else if (D == 0.0) res.push_back((-1.0 * b) / (2.0 * a));
    else res.resize(0);
    return res;
}
int GetDistinctRealRootCount(double a, double b, double c) {
    vector<double>x = Solution(a, b, c);
    return x.size();
}

void TestDistinctRealRootCount() {

    AssertEqual(GetDistinctRealRootCount(0, 0, 0), 0, " 000 ");
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, " 001 ");
    AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, " 010 ");
    AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, " 011 ");
    AssertEqual(GetDistinctRealRootCount(1, 0, 0), , " 100 ");
    AssertEqual(GetDistinctRealRootCount(1, 0, 1), , " 101 ");
    AssertEqual(GetDistinctRealRootCount(1, 1, 0), , " 110 ");
    AssertEqual(GetDistinctRealRootCount(1, 1, 1), , " 111 ");

}

void TestAreQuadratic() {
    Assert()
}
void EXECUTE() {
    TestRunner runner;
    runner.RunTest(TestDis, "TestDis");
    runner.RunTest(TestDistinctRealRootCount, "TestDistinctRealRootCount");
}

int main() {
    EXECUTE();

    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << " :" << GetDistinctRealRootCount(a, b, c) << endl;
    }
    return 0;
}

*/