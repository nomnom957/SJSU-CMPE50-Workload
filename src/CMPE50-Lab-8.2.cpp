//============================================================================
// Name        : CMPE50-Lab-8.2.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char* delete_repeats(const char arr[], int size) {
    bool seen[256] = {false};
    int uniqueCount = 0;

    for (int i = 0; i < size; ++i) {
        unsigned char ch = static_cast<unsigned char>(tolower(arr[i]));
        if (!seen[ch]) {
            seen[ch] = true;
            ++uniqueCount;
        }
    }

    char* result = new char[uniqueCount + 1];
    bool used[256] = {false};
    int j = 0;

    for (int i = 0; i < size; ++i) {
        unsigned char ch = static_cast<unsigned char>(tolower(arr[i]));
        if (!used[ch]) {
            used[ch] = true;
            result[j++] = arr[i];
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char str[100] = "to be or not to be";
    int size = strlen(str);

    char* noRepeat = delete_repeats(str, size);

    cout << noRepeat << endl;

    delete[] noRepeat;
    return 0;
}

/*
 * to bern
 */
