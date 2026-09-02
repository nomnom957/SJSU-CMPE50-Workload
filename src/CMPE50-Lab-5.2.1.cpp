//============================================================================
// Name        : CMPE50-Lab-5.2.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool IsAlphabet(char ch) {
    return isalpha(static_cast<unsigned char>(ch));
}

bool IsCapitalizedWord(const string& w) {
    if (w.empty()) return false;
    if (!isupper(static_cast<unsigned char>(w[0]))) return false;
    for (size_t i = 1; i < w.size(); ++i)
        if (!islower(static_cast<unsigned char>(w[i]))) return false;
    return true;
}

string CapFirst(string s) {
    if (!s.empty()) s[0] = static_cast<char>(toupper(static_cast<unsigned char>(s[0])));
    return s;
}

string ReplacePronoun(const string& word) {
    string lower;
    lower.reserve(word.size());
    for (char c : word) lower += static_cast<char>(tolower(static_cast<unsigned char>(c)));

    bool cap = IsCapitalizedWord(word);

    if (lower == "he") {
        return cap ? (CapFirst("she") + " or " + CapFirst("he")) : "she or he";
    } else if (lower == "him") {
        return cap ? (CapFirst("her") + " or " + CapFirst("him")) : "her or him";
    } else if (lower == "his") {
        return cap ? (CapFirst("her(s)") + " or " + CapFirst("his")) : "her(s) or his";
    }
    return word;
}

int main() {
    cout << "Enter a sentence (type 'done' to stop): " << endl;

    string sentence;
    while (true) {
        if (!getline(cin, sentence)) break;
        if (sentence == "done" || sentence == "Done") break;

        string osentence;
        string word;

        for (size_t i = 0; i < sentence.length(); ++i) {
            char ch = sentence[i];
            if (IsAlphabet(ch)) {
                word += ch;
            } else {
                if (!word.empty()) {
                    osentence += ReplacePronoun(word);
                    word.clear();
                }
                osentence += ch;
            }
        }
        if (!word.empty()) {
            osentence += ReplacePronoun(word);
        }

        if (!osentence.empty() && IsAlphabet(osentence[0])) {
            osentence[0] = static_cast<char>(toupper(static_cast<unsigned char>(osentence[0])));
        }

        cout << "Suggestion: " << osentence << "\n\n";
        cout << "Enter another sentence (or 'done' to stop):" << endl;
    }

    return 0;
}

/*
 * Enter a sentence (type 'done' to stop):
 * See an adviser, talk to him, and listen to him.
 * Suggestion: See an adviser, talk to her or him, and listen to her or him.
 *
 * Enter another sentence (or 'done' to stop):
 * done
 *
 */
