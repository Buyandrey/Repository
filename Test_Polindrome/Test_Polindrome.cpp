#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool IsPalindrom(const string& str) {

    if (str.size() == 0 || str.size() == 1) {
        return true;
    }
    else {
        vector<char> strv;
        for (const char& x : str) {
            if (x == '\0') break;
            strv.push_back(x);
        }

        vector<char> rtsv;
        for (size_t i = 0; i < strv.size(); i++)
            rtsv.push_back(strv.at(strv.size()-(i+1)));

        return (strv == rtsv);
    }
}

void Test() {

    AssertEqual(IsPalindrom("1"), 1, "1");
    AssertEqual(IsPalindrom("11"), 1, "11");
    AssertEqual(IsPalindrom("12"), 0, "12");
    AssertEqual(IsPalindrom("121"), 1, "121");
    AssertEqual(IsPalindrom("1221"), 1, "1221");
    AssertEqual(IsPalindrom("1211"), 0, "1211");
    AssertEqual(IsPalindrom(""), 1, "-");
}
void TestAll(){
    TestRunner runner;
    runner.RunTest(Test, "Test");
}
int main() {
    TestAll();
    // добавьте сюда свои тесты
    //while (1) {
    //    string s;
    //    cin >> s;
    //    cout << IsPalindrom(s) << endl;
    //}
    return 0;
}
