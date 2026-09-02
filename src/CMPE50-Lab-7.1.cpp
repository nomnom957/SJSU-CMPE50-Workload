//============================================================================
// Name        : CMPE50-Lab-7.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

class Rational {
public:
    Rational();
    Rational(int n, int d);
    void input(istream& in);
    void output(ostream& out) const;
    void normalize();

    friend Rational add(const Rational& r1, const Rational& r2);
    friend Rational subtract(const Rational& r1, const Rational& r2);
    friend Rational multiply(const Rational& r1, const Rational& r2);
    friend Rational divide(const Rational& r1, const Rational& r2);

    friend bool equal(const Rational& r1, const Rational& r2);
    friend bool less_than(const Rational& r1, const Rational& r2);

private:
    int numerator;
    int denominator;

    int gcd(int n1, int n2);
};

int main() {
    Rational r1, r2;
    cout << "Input r1 fraction (a/b): ";
    r1.input(cin);
    cout << "r1: ";
    r1.output(cout);

    cout << "Input r2 fraction (a/b): ";
    r2.input(cin);
    cout << "r2: ";
    r2.output(cout);

    cout << "r1 + r2: ";
    add(r1, r2).output(cout);

    cout << "r1 - r2: ";
    subtract(r1, r2).output(cout);

    cout << "r1 * r2: ";
    multiply(r1, r2).output(cout);

    cout << "r1 / r2: ";
    divide(r1, r2).output(cout);

    if (equal(r1, r2)) {
        cout << "r1 equals r2\n";
    } else if (less_than(r1, r2)) {
        cout << "r1 is less than r2\n";
    } else {
        cout << "r1 is greater than r2\n";
    }
}

Rational::Rational() : numerator(1), denominator(1) {}

Rational::Rational(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0) {
        cerr << "Denominator can't be 0.\n";
        exit(1);
    }
    normalize();
}

void Rational::input(istream& in) {
    char slash;
    int n, d;
    in >> n >> slash >> d;
    if (!in || slash != '/') {
        cerr << "Bad input (use a/b).\n";
        exit(1);
    }
    numerator = n;
    denominator = d;
    if (denominator == 0) {
        cerr << "Denominator can't be 0.\n";
        exit(1);
    }
    normalize();
}

void Rational::output(ostream& out) const {
    if (numerator == 0) {
        out << 0 << '\n';
    } else if (numerator == denominator) {
        out << 1 << '\n';
    } else {
        out << numerator << " / " << denominator << '\n';
    }
}

void Rational::normalize() {
    if (numerator == 0) { denominator = 1; return; }

    int g = gcd(numerator, denominator);
    numerator   /= g;
    denominator /= g;

    if (denominator < 0) { denominator = -denominator; numerator = -numerator; }
    numerator = (numerator < 0) ? -std::abs(numerator) : std::abs(numerator);
    denominator = std::abs(denominator);
}

int Rational::gcd(int n1, int n2) {
    n1 = std::abs(n1);
    n2 = std::abs(n2);
    while (n2 != 0) {
        int t = n1 % n2;
        n1 = n2;
        n2 = t;
    }
    return (n1 == 0) ? 1 : n1;
}

Rational add(const Rational& r1, const Rational& r2) {
    int n = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    int d = r1.denominator * r2.denominator;
    return Rational(n, d);
}

Rational subtract(const Rational& r1, const Rational& r2) {
    int n = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    int d = r1.denominator * r2.denominator;
    return Rational(n, d);
}

Rational multiply(const Rational& r1, const Rational& r2) {
    int n = r1.numerator * r2.numerator;
    int d = r1.denominator * r2.denominator;
    return Rational(n, d);
}

Rational divide(const Rational& r1, const Rational& r2) {
    if (r2.numerator == 0) {
        cerr << "Divide by zero rational.\n";
        exit(1);
    }
    int n = r1.numerator * r2.denominator;
    int d = r1.denominator * r2.numerator;
    return Rational(n, d);
}

bool equal(const Rational& r1, const Rational& r2) {
    return static_cast<long long>(r1.numerator) * r2.denominator
         == static_cast<long long>(r2.numerator) * r1.denominator;
}

bool less_than(const Rational& r1, const Rational& r2) {
    return static_cast<long long>(r1.numerator) * r2.denominator
         <static_cast<long long>(r2.numerator) * r1.denominator;
}

/*
 * Input r1 fraction (a/b): 1/2
 * r1: 1 / 2
 * Input r2 fraction (a/b): 3/4
 * r2: 3 / 4
 * r1 + r2: 5 / 4
 * r1 - r2: -1 / 4
 * r1 * r2: 3 / 8
 * r1 / r2: 2 / 3
 * r1 is less than r2
 */
