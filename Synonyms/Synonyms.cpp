#include "Synonyms.h"

void AddSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word) {
    synonyms[second_word].insert(first_word);
    synonyms[first_word].insert(second_word);
}
size_t GetSynonymsCount(Synonyms& synonyms, const string& word) {
    return synonyms[word].size();
}
bool AreSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word) {
    if (synonyms[first_word].count(second_word) == 1)
        return 1;
    else
        return 0;

}