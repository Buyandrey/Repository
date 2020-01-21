#include "Tests.h"

void TestGetSynonymsCount() {
    {
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"), 0u, "Count4Empty");
    }
    {
        Synonyms synonyms = {
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"b",{"a"}},
        };
        AssertEqual(GetSynonymsCount(synonyms, "a"), 2u, "Count4a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 1u, "Count4b");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0u, "Count4z");
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
        AssertEqual(empty, expected, "empty != expected");
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
        AssertEqual(synonyms, expected, "synonyms != expected");
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
        Assert(!AreSynonyms(synonyms, "b", "c"), "synonyms b c");
    }

}
void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
    tr.RunTest(TestGetSynonymsCount, "TestGetSynonymsCount");
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
}
