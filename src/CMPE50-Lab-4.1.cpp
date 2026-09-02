//============================================================================
// Name        : CMPE50-Lab-4.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
	const int SIZE = 1000;
	char arr[SIZE];
	char ch;
	int index = 0;

	ifstream fin("input.txt");
	if (!fin) {
		cout << "File couldn't be opened.";
		return 1;
	}

	while (fin.get(ch) && index < SIZE - 1) {
		if (isalpha(static_cast<unsigned char>(ch))) {
			arr[index] = toupper(static_cast<unsigned char>(ch));
			index++;
		}
	}
	arr[index] = '\0';
	fin.close();

	ofstream fout("LabOutput4-1.txt");
	if (!fout) {
		cout << "File couldn't be opened.";
		return 1;
	}

	fout << arr;
	fout.close();

	cout << "Output written in LabOutput4-1.txt." << endl;

	return 0;
}

/*
 * input.txt:
 * q
 * w
 * e
 * r
 * t
 * y
 *
 * LabOutput4-1.txt:
 * QWERTY
 *
 */
