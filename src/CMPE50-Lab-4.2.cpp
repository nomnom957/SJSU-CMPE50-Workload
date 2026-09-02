//============================================================================
// Name        : CMPE50-Lab-4.2.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const int SIZE = 50;
	int arr[SIZE];
	int size = 0;

	int countarr[11] = {0};

	char choice;
	cout << "Enter numbers with keyboard (k), or file (f)?: ";
	cin >> choice;

	if (choice == 'k' || choice == 'K') {
		cout << "Enter numbers from 1-10 into keyboard (end with -1): ";
		int num;
		while (cin >> num && num != -1 && size < SIZE) {
			arr[size++] = num;
		}
	} else if (choice == 'f' || choice == 'F') {
		string filename;
		cout << "Enter file name: ";
		cin >> filename;

		ifstream fin(filename);
		if (!fin) {
			cout << "Following file couldn't be opened: " << filename << endl;
			return 1;
		}

		int num;
		while (fin >> num && size < SIZE) {
			arr[size++] = num;
		}
		fin.close();

	} else {
		cout << "Invalid choice." << endl;
		return 1;
	}

	for (int i = 0; i < size; i++) {
		int num = arr[i];
		if (num >= 1 && num <= 10) {
			countarr[num]++;
		}
	}

	ofstream fout("LabOutput4-2.txt");
	if (!fout) {
		cout << "Couldn't create the file: LabOutput4-2.txt" << endl;
		return 1;
	}

	cout << "N  Count" << endl;
	fout << "N  Count" << endl;

	for (int n = 10; n >= 1; n--) {
		if (countarr[n] > 0) {
			cout << n << "  " << countarr[n] << endl;
			fout << n << "  " << countarr[n] << endl;
		}
	}

	    fout.close();

	return 0;
}

/*
 * LabInput4-2.txt:
 * 4
 * 4
 * 4
 * 5
 * 5
 * 5
 * 5
 * 6
 * 1
 * 3
 *
 * Enter numbers with keyboard (k), or file (f)?: f
 * Enter file name: LabInput4-2.txt
 * N  Count
 * 6  1
 * 5  4
 * 4  3
 * 3  1
 * 1  1
 *
 */
