//============================================================================
// Name        : CMPE50-Lab-4.3.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int num1, num2;

    ifstream inputFile("LabInput4-3.txt");
    ifstream inputFile2("LabInput4-4.txt");
    ofstream outputFile("LabOutputBoth.txt");

    if (!inputFile || !inputFile2 || !outputFile) {
        cerr << "Error opening one of the files." << endl;
        return 1;
    }

    bool hasNum1 = static_cast<bool>(inputFile >> num1);
    bool hasNum2 = static_cast<bool>(inputFile2 >> num2);

    while (hasNum1 && hasNum2) {
        if (num1 < num2) {
            outputFile << num1 << ' ';
            hasNum1 = static_cast<bool>(inputFile >> num1);
        } else {
            outputFile << num2 << ' ';
            hasNum2 = static_cast<bool>(inputFile2 >> num2);
        }
    }

    while (hasNum1) {
        outputFile << num1 << ' ';
        hasNum1 = static_cast<bool>(inputFile >> num1);
    }
    while (hasNum2) {
        outputFile << num2 << ' ';
        hasNum2 = static_cast<bool>(inputFile2 >> num2);
    }

    cout << "Check LabOutputBoth.txt for results." << endl;
    return 0;
}

/*
 * LabInput4-3.txt:
 * 6 13 15 22 33 76 88 99
 *
 * LabInput4-4.txt:
 * 31 40 52 60 62 89
 *
 * LabOutputBoth.txt:
 * 6 13 15 22 31 33 40 52 60 62 76 88 89 99
 *
 */
