#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <sstream>

using namespace std;

using  Synonyms= map<string, set<string>>;

// �������

void AddSynonyms(Synonyms& synonyms,const string& first_word, const string& second_word) {
    synonyms[second_word].insert(first_word);
    synonyms[first_word].insert(second_word);//+
    //synonyms[first_word].insert(first_word);//-

}

size_t GetSynonymsCount(Synonyms& synonyms, const string& word) {
    return synonyms[word].size();
}

bool AreSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word) {
    if (synonyms[first_word].count(second_word) == 1)//1
        return 1;
    else
        return 0;

}

// �������

template<class T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first)  os << ", ";
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V> ostream& operator<<(ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first)  os << ", ";
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T,class U> void AssertEqual(const T& t, const U& u,const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: "<<t<<" != "<<u
            <<" Hint: "<<hint;
        throw runtime_error(os.str());
    }
}

class TestRunner {
private:
    int fail_count=0;
public:
    template<class TestFunc> void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << "(cerr) " << test_name << " OK.\n";
        }
        catch (runtime_error & e) {
            fail_count++;
            cerr << "(cerr) " << test_name << " fail: " << e.what() << endl;
        }
    }
    ~TestRunner() {
        if (fail_count > 0) {
            cerr << "(cerr) "<<endl<< fail_count << " tests failed. Terminate....";
            exit(69);
        }
    }
};

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

// ����� �������

void TestGetSynonymsCount() {
    {
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"), 0u,"Count4Empty");
    }
    {
        Synonyms synonyms = {
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"b",{"a"}},
        };
        AssertEqual(GetSynonymsCount(synonyms, "a"), 2u,"Count4a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 1u,"Count4b");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0u,"Count4z");
    }
}

void TestAddSynonyms() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = { 
            {"a",{"b"}},
            {"b",{"a"}}
        };
        AssertEqual(empty,expected,"empty != expected");
    }

    {
        Synonyms synonyms = {
            {"a",{"b"}},
            {"b",{"a","c"}},
            {"c",{"b"}}
        };
        AddSynonyms(synonyms, "a", "c");
        Synonyms expected = {
            {"a",{"b","c"}},
            {"b",{"a","c"}},
            {"c",{"b","a"}}
        };
        AssertEqual(synonyms, expected,"synonyms != expected");
    }
}

void TestAreSynonyms() {
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
        Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
    }
    {
        Synonyms synonyms = {
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"c",{"a"}},
        };
        Assert(AreSynonyms(synonyms, "a", "b"), "synonyms a b");
        Assert(AreSynonyms(synonyms, "b", "a"), "synonyms b a");
        Assert(AreSynonyms(synonyms, "a", "c"), "synonyms a c");
        Assert(AreSynonyms(synonyms, "c", "a"), "synonyms c a");
        Assert(!AreSynonyms(synonyms, "b", "c"),"synonyms b c");
    }

}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
    tr.RunTest(TestGetSynonymsCount, "TestGetSynonymsCount");
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
}

// ����������

int main() {

    TestAll();

    int q;
    cin >> q;

    Synonyms synonyms;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "ADD") {
            string first_word, second_word;
            cin >> first_word >> second_word;
            AddSynonyms(synonyms, first_word, second_word);
        }
        else if (operation_code == "COUNT") {

            string word;
            cin >> word;
            cout << GetSynonymsCount(synonyms,word) << endl;

        }
        else if (operation_code == "CHECK") {

            string first_word, second_word;
            cin >> first_word >> second_word;
            if (AreSynonyms(synonyms, first_word, second_word)) 
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
