//============================================================================
// Name        : CMPE50-Lab-6.3.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parallelogram {
private:
	double base, height, area;

public:
	Parallelogram (double b, double h) {
		base = b;
		height = h;
		area = 0.0;
	}

	void Calculate() {
		area = base * height;
	}

	void Display () {
		cout << "The area of the parallelogram is: " << area << endl;
	}
};

int main() {
	double base, height;

	cout << "Enter parallelogram base: ";
	cin >> base;

	cout << "Enter parallelogram height: ";
	cin >> height;

	Parallelogram par(base, height);
	par.Calculate();
	par.Display();

	return 0;
}

/*
 * Enter parallelogram base: 10
 * Enter parallelogram height: 5
 * The area of the parallelogram is: 50
 */
