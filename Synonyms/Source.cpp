#include "Tests.h"
#include "Synonyms.h"

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void _Synonyms() {
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
            cout << GetSynonymsCount(synonyms, word) << endl;

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
}

int main() {

    TestAll();
    _Synonyms();
    
    return 0;
}
