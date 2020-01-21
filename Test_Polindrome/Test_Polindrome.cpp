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

//bool IsPalindrom(const string& str) {
//
//    string jojo = "jo jo";
//    if (str.size() == 0 || str.size() == 1) {
//        return true;
//    }
//    else {
//        vector<char> strv;
//        for (const char& x : str) {
//            if (x == '\0') break;
//            strv.push_back(x);
//        }
//
//        vector<char> rtsv;
//        for (size_t i = 0; i < strv.size(); i++)
//            rtsv.push_back(strv.at(strv.size()-(i+1)));
//
//        return (strv == rtsv);
//    }
//}

void Test() {

    AssertEqual(IsPalindrom("1"), 1, "1");
    AssertEqual(IsPalindrom("11"), 1, "11");
    AssertEqual(IsPalindrom("12"), 0, "12");
    AssertEqual(IsPalindrom("121"), 1, "121");
    AssertEqual(IsPalindrom("1221"), 1, "1221");
    AssertEqual(IsPalindrom("1211"), 0, "1211");
    AssertEqual(IsPalindrom("11211"), 1, "11211");
    AssertEqual(IsPalindrom("11311"), 1, "11311");
    AssertEqual(!IsPalindrom("2111"), 1, "!2111");
    AssertEqual(!IsPalindrom("1121"), 1, "1121");
    AssertEqual(!IsPalindrom("1112"), 1, "!1112");
    AssertEqual(IsPalindrom("777777"), 1, "777777");
    AssertEqual(IsPalindrom("777778"), 0, "777778");

    AssertEqual(IsPalindrom(""), 1, "-");

    AssertEqual(IsPalindrom("madam"), 1,"a1");
    AssertEqual(IsPalindrom("lool"), 1, "a2");
    AssertEqual(IsPalindrom("o"), 1, "a3");
    AssertEqual(IsPalindrom(""), 1, "a4");
    AssertEqual(IsPalindrom(" "), 1, "a5");
    AssertEqual(IsPalindrom("  "), 1, "a6");
    AssertEqual(IsPalindrom("top pot"), 1, "a7");
    AssertEqual(IsPalindrom("o lol o"), 1, "a8");
    AssertEqual(IsPalindrom(" olo "), 1, "a9");
    AssertEqual(IsPalindrom("olol"), 0, "a10");
    AssertEqual(IsPalindrom("motor"), 0, "a11");
    AssertEqual(IsPalindrom("topo gun"), 0, "a12");
    AssertEqual(IsPalindrom("olol "), 0, "a13");
    AssertEqual(IsPalindrom(" lol"), 0, "a14");
   // AssertEqual(IsPalindrom("olo" + '\n'), 0, "a15");
}
void TestAll(){
    TestRunner runner;
    runner.RunTest(Test, "Test");
}
int main() {
    TestAll();
     //добавьте сюда свои тесты
    //while (1) {
    //    string s;
    //    cin >> s;
    //    cout << IsPalindrom(s) << endl;
    //}
    return 0;
}
/*coursera
#include <algorithm>
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
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
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

void TestIsPalindrom() {
  Assert(IsPalindrom(""), "empty string is a palindrome");
  Assert(IsPalindrom("a"), "one letter string is a palindrome");
  Assert(IsPalindrom("abba"), "abba is a palindrome");
  Assert(IsPalindrom("abXba"), "abXba is a palindrome");
  Assert(IsPalindrom("a b X b a"), "`a b X b a` is a palindrome");
  Assert(IsPalindrom("  ABBA  "), "`  ABBA  ` is a palindrome");

  Assert(!IsPalindrom("XabbaY"), "XabbaY is not a palindrome");
  Assert(!IsPalindrom("abXYba"), "abXYba is not a palindrome");
  Assert(!IsPalindrom("Xabba"), "Xabba is not a palindrome");
  Assert(!IsPalindrom("abbaX"), "abbaX is not a palindrome");
  Assert(
    !IsPalindrom("was it a car or a cat i saw"),
    "`was it a car or a cat i saw` is not a palindrome because spaces do not match"
  );
  Assert(!IsPalindrom("ABBA   "), "`ABBA   ` is not a palindrome");
  Assert(!IsPalindrom("  ABBA"), "`  ABBA` is not a palindrome");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestIsPalindrom, "TestIsPalindrom");
  return 0;
}

*/