//============================================================================
// Name        : CMPE50-Lab-9.2.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Complex.h"
#include <cmath>
#include <ostream>
#include <iostream>

Complex::Complex() : real(0.0), imaginary(0.0) {}
Complex::Complex(double real_part) : real(real_part), imaginary(0.0) {}
Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imaginary - b.imaginary);
}

Complex operator*(const Complex& a, const Complex& b) {
    const double r = a.real * b.real - a.imaginary * b.imaginary;
    const double i = a.real * b.imaginary + a.imaginary * b.real;
    return Complex(r, i);
}

std::ostream& operator<<(std::ostream& os, const Complex& z) {
    os << z.real;
    if (z.imaginary < 0) os << " - " << std::abs(z.imaginary) << "i";
    else                 os << " + " << z.imaginary << "i";
    return os;
}

int main() {
    Complex x(2.0, -3.0);
    Complex y(-7.0, 5.0);

    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";

    std::cout << "x + y = " << (x + y) << "\n";
    std::cout << "x - y = " << (x - y) << "\n";
    std::cout << "x * y = " << (x * y) << "\n";

    Complex r = 3.0;
    std::cout << "x + 3 = " << (x + r) << "\n";
    std::cout << "3 * y = " << (r * y) << "\n";

    return 0;
}

/*
 * x = 2 - 3i
 * y = -7 + 5i
 * x + y = -5 + 2i
 * x - y = 9 - 8i
 * x * y = 1 + 31i
 * x + 3 = 5 - 3i
 * 3 * y = -21 + 15i
 */
