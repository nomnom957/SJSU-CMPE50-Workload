//============================================================================
// Name        : CMPE50-Lab-6.2.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Counter {
private:
    unsigned int count;

public:
    Counter() : count(0) {}
    Counter(unsigned int value) : count(value) {}
    void increase() {
        count++;
    }

    void decrease() {
        if (count > 0)
            count--;
        else
            cout << "Can't count below zero" << endl;
    }

    void print() const {
        cout << "Current count: " << count << endl;
    }
};

int main() {
    cout << "Testing counter class:\n";

    Counter c1;
    Counter c2(5);

    c1.print();
    c2.print();

    cout << endl << "Increasing c1 three times:" << endl;
    c1.increase();
    c1.increase();
    c1.increase();
    c1.print();

    cout << endl << "Decreasing c1 four times:" << endl;
    c1.decrease();
    c1.decrease();
    c1.decrease();
    c1.decrease();
    c1.print();

    cout << endl << "Increasing c2 once:" << endl;
    c2.increase();
    c2.print();

    return 0;
}

/*
 * Testing counter class:
 * Current count: 0
 * Current count: 5
 *
 * Increasing c1 three times:
 * Current count: 3
 *
 * Decreasing c1 four times:
 * Can't count below zero
 * Current count: 0
 *
 * Increasing c2 once:
 * Current count: 6
 */
