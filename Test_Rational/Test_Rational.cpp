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
//int GreatestCommonDivisor(int a, int b) {
//    if (b == 0) {
//        return a;
//    }
//    else {
//        return GreatestCommonDivisor(b, a % b);
//    }
//}
//
//class Rational {
//public:
//    Rational() {
//        numerator = 0;
//        denominator = 1;
//    }
//    Rational(int new_numerator, int new_denominator) {
//        if (new_denominator == 0) {
//            // бросаем исключение в случае нулевого знаменателя
//            throw invalid_argument("");
//        }
//        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
//        numerator = new_numerator / gcd;
//        denominator = new_denominator / gcd;
//        if (denominator < 0) {
//            denominator = -denominator;
//            numerator = -numerator;
//        }
//    }
//
//    int Numerator() const {
//        return numerator;
//    }
//
//    int Denominator() const {
//        return denominator;
//    }
//
//private:
//    int numerator;
//    int denominator;
//};
//
//Rational operator * (const Rational& lhs, const Rational& rhs) {
//    return {
//        lhs.Numerator() * rhs.Numerator(),
//        lhs.Denominator() * rhs.Denominator()
//    };
//}
//
//Rational operator / (const Rational& lhs, const Rational& rhs) {
//    // проверяем делитель на 0 (что равносильно проверке на 0 его числителя)
//    if (rhs.Numerator() == 0) {
//        throw domain_error("");
//    }
//    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
//}

void Tests() {
    {// stock create
        Rational e;
        AssertEqual(e.Denominator(), 1, "StockDenum==1");
        AssertEqual(e.Numerator(), 0, "StockNom==0");
    }
    {// manual create 1
        Rational e(1,2);
        AssertEqual(e.Denominator(), 2, "ManualDenum==2");
        AssertEqual(e.Numerator(), 1, "ManualNom==1");
    }
    {// manual create 2
        Rational e(8, 18);
        AssertEqual(e.Denominator(), 9, "ManualDenum==9");
        AssertEqual(e.Numerator(), 4, "ManualNom==4");
    }
    {// manual create 3
        Rational e(-8, -18);
        AssertEqual(e.Denominator(), 9, "ManualDenum==9'");
        AssertEqual(e.Numerator(), 4, "ManualNom==4'");
    }
    {// manual create 4, Num<0
        Rational e(-8, 18);
        AssertEqual(e.Denominator(), 9, "ManualDenum==9");
        AssertEqual(e.Numerator(), -4, "ManualNom==-4");
    }
    {// manual create 4, Den<0
        Rational e(8, -18);
        AssertEqual(e.Denominator(), 9, "ManualDenum==9'");
        AssertEqual(e.Numerator(), -4, "ManualNom==-4'");
    }
    {// manual create 5, Num=0
        Rational e(0, 5);
        AssertEqual(e.Denominator(), 1, "ManualDenum==1'");
        AssertEqual(e.Numerator(), 0, "ManualNom==0'");
    }
}

void RunAllTests() {
    TestRunner runner;
    runner.RunTest(Tests, "Tests");
}

int main() {
    RunAllTests();
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

void TestPredefined() {
  AssertEqual(Rational(1, 1).Numerator(), 1, "Canonical form of 1/1 is 1/1");
  AssertEqual(Rational(1, 1).Denominator(), 1, "Canonical form of 1/1 is 1/1");
  AssertEqual(Rational(3, 5).Numerator(), 3, "Canonical form of 3/5 is 3/5");
  AssertEqual(Rational(3, 5).Denominator(), 5, "Canonical form of 3/5 is 3/5");
  AssertEqual(Rational(2147483647, 2147483647).Numerator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
  AssertEqual(Rational(2147483647, 2147483647).Denominator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
  AssertEqual(Rational(-5, 4).Numerator(), -5, "Canonical form of -5/4 is -5/4");
  AssertEqual(Rational(-5, 4).Denominator(), 4, "Canonical form of -5/4 is -5/4");
  AssertEqual(Rational(5, -4).Numerator(), -5, "Canonical form of 5/-4 is -5/4");
  AssertEqual(Rational(5, -4).Denominator(), 4, "Canonical form of 5/-4 is -5/4");
  AssertEqual(Rational(-6, -2).Numerator(), 3, "Canonical form of -6/-2 is 3/1");
  AssertEqual(Rational(-6, -2).Denominator(), 1, "Canonical form of -6/-2 is 3/1");
  AssertEqual(Rational(21, 56).Numerator(), 3, "Canonical form of 21/56 is 3/8");
  AssertEqual(Rational(21, 56).Denominator(), 8, "Canonical form of 21/56 is 3/8");
  AssertEqual(Rational(0, 100).Numerator(), 0, "Canonical form of 0/100 is 0/1");
  AssertEqual(Rational(0, 100).Denominator(), 1, "Canonical form of 0/100 is 0/1");
  AssertEqual(Rational().Numerator(), 0, "Canonical form of default constructed is 0/1");
  AssertEqual(Rational().Denominator(), 1, "Canonical form of default constructed is 0/1");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestPredefined, "TestPredefined");
  return 0;
}
*/