#pragma once

#include <string>
#include <set>
#include <map>

using namespace std;

using  Synonyms = map<string, set<string>>;

void AddSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word);
size_t GetSynonymsCount(Synonyms& synonyms, const string& word);
bool AreSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word);
