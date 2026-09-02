//============================================================================
// Name        : CMPE50-Lab-5.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool IsWhitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

int main() {
    char str[200];
    char out[200];

    cin.getline(str, 200, '.');

    bool is_initial = true;
    bool is_firstblank = false;
    int n = strlen(str);
    int j = 0;

    for (int i = 0; i < n; ++i) {
        if (IsWhitespace(str[i])) {
            if (is_initial) {
                continue;
            }

            if (!is_firstblank) {
                out[j++] = ' ';
                is_firstblank = true;
            }
        } else {
            if (is_initial) is_initial = false;

            is_firstblank = false;

            out[j++] = static_cast<char>(tolower(static_cast<unsigned char>(str[i])));
        }
    }

    if (j > 0 && out[j - 1] == ' ') --j;

    out[j] = '\0';

    bool newWord = true;
    for (int k = 0; k < j; ++k) {
        if (isalpha(static_cast<unsigned char>(out[k]))) {
            if (newWord) {
                out[k] = static_cast<char>(toupper(static_cast<unsigned char>(out[k])));
                newWord = false;
            } else {
                out[k] = static_cast<char>(tolower(static_cast<unsigned char>(out[k])));
            }
        } else if (out[k] == ' ') {
            newWord = true;
        }
    }

    if (j == 0) {
        cout << "." << endl;
    } else {
        cout << out << "." << endl;
    }
    return 0;
}

/*
 * noW   is  thE    TiMe
 * for    aLl
 *
 * GOOD   MEN to coMe to   tHe aId
 * of  ThE    CounTRY.
 * Now Is The Time For All Good Men To Come To The Aid Of The Country.
 */
