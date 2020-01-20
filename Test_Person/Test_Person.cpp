#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// ���� ��� ����������, ���������� ������ ������
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

//string FindNameByYear(const map<int, string>& names, int year) {
//    string name;  // ���������� ��� ����������
//
//    // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
//    for (const auto& item : names) {
//        // ���� ��������� ��� �� ������ �������, ��������� ���
//        if (item.first <= year) {
//            name = item.second;
//        }
//        else {
//            // ����� ���� ������������, ��� ��� ��� ������ � ��� ����������� ��������� � ��������
//            break;
//        }
//    }
//
//    return name;
//}

//class Person {
//public:
//    void ChangeFirstName(int year, const string& first_name) {
//        first_names[year] = first_name;
//    }
//    void ChangeLastName(int year, const string& last_name) {
//        last_names[year] = last_name;
//    }
//    string GetFullName(int year) {
//        // �������� ��� � ������� �� ��������� �� ��� year
//        const string first_name = FindNameByYear(first_names, year);
//        const string last_name = FindNameByYear(last_names, year);
//
//        // ���� � ���, � ������� ����������
//        if (first_name.empty() && last_name.empty()) {
//            return "Incognito";
//
//            // ���� ���������� ������ ���
//        }
//        else if (first_name.empty()) {
//            return last_name + " with unknown first name";
//
//            // ���� ���������� ������ �������
//        }
//        else if (last_name.empty()) {
//            return first_name + " with unknown last name";
//
//            // ���� �������� � ���, � �������
//        }
//        else {
//            return first_name + " " + last_name;
//        }
//    }
//
//private:
//    map<int, string> first_names;
//    map<int, string> last_names;
//};


void TestAllMethodsInComplex() {
    /*

    1) �������� ��� ���������� Incognito, ���� ��� �� ����� �� �������
    2) �������� ��� � ������ � ��� ������ ���� ����� with unknown last name 
    3) �������� ��� � �������� � ��� ����� ���� ����� with unknown first name
    4) �������� �������� ��������� � ���
    5) �������� �������� ��������� � �������
    6) �������� �������� ��������� � ��� � �������
    7) ����� ��� ������ �������
    8) ����� ������� ������ ���
    9) ����� ��


    */
    {//1
        Person Empty;
        AssertEqual(Empty.GetFullName(1990), "Incognito", "INC");
    }
    {//2
        Person Empty;
        Empty.ChangeFirstName(1990,"FirstName");
        AssertEqual(Empty.GetFullName(1990),"FirstName with unknown last name","ULN");
    }
    {//3
        Person Empty;
        Empty.ChangeLastName(1990, "LastName");
        AssertEqual(Empty.GetFullName(1990), "LastName with unknown first name", "UFN");
    }

    {//4
        Person Empty;
        Empty.ChangeFirstName(1990, "FirstName1");
        Empty.ChangeFirstName(1991, "FirstName2");

        AssertEqual(Empty.GetFullName(1991), "FirstName2 with unknown last name", "ULN2");
    }

    {//5
        Person Empty;
        Empty.ChangeLastName(1990, "LastName1");
        Empty.ChangeLastName(1991, "LastName2");

        AssertEqual(Empty.GetFullName(1991), "LastName2 with unknown first name", "LN2");
    }

    {//6
        Person Empty;
        Empty.ChangeFirstName(1990, "FirstName");
        Empty.ChangeLastName(1990, "LastName");

        AssertEqual(Empty.GetFullName(1990), "FirstName LastName", "FN_LN");
    }
    {//7 ����� ��� ������ �������
        Person Empty;
        Empty.ChangeFirstName(1990, "FirstName1");
        Empty.ChangeLastName(1990, "LastName1");
        Empty.ChangeFirstName(1991, "FirstName2");

        AssertEqual(Empty.GetFullName(1991), "FirstName2 LastName1", "FN2_LN1");
    }
    {//8 ����� ������� ������ ���
        Person Empty;
        Empty.ChangeFirstName(1990, "FirstName1");
        Empty.ChangeLastName(1990, "LastName1");
        Empty.ChangeLastName(1991, "LastName2");


        AssertEqual(Empty.GetFullName(1991), "FirstName1 LastName2", "FN1_LN2");
    }
    {//8 ����� ��
        Person Empty;
        Empty.ChangeFirstName(1990, "FirstName1");
        Empty.ChangeLastName(1990, "LastName1");
        Empty.ChangeFirstName(1991, "FirstName2");
        Empty.ChangeLastName(1991, "LastName2");


        AssertEqual(Empty.GetFullName(1991), "FirstName2 LastName2", "FN2_LN2");
    }
}

void RunAllTests() {
    TestRunner runner;
    runner.RunTest(TestAllMethodsInComplex, "TestAllMethodsInComplex");
}
int main() {
    RunAllTests();

    return 0;
}
/*coursera
#include <iostream>
#include <map>
#include <ostream>
#include <random>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  bool first = true;
  for (const auto &kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template <class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string &hint) { AssertEqual(b, true, hint); }

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string &test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception &e) {
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

void TestPredefinedLastNameFirst() {
    Person person;

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeFirstName(1967, "Polina");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
}

void TestPredefined() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");

    person.ChangeFirstName(1969, "Appolinaria");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1969), "Appolinaria Sergeeva");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1967), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1968), "Polina Volkova");
    AssertEqual(person.GetFullName(1969), "Appolinaria Volkova");

}

int main() {
    TestRunner runner;
    runner.RunTest(TestPredefined, "TestPredefined");
    runner.RunTest(TestPredefinedLastNameFirst, "TestPredefinedLastNameFirst");
    return 0;
}
*/