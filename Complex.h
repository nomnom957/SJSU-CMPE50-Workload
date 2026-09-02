#ifndef COMPLEX_H
#define COMPLEX_H

#include <ostream>

class Complex {
public:
    double real;
    double imaginary;

    Complex();
    Complex(double real_part);
    Complex(double r, double i);

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);

    friend std::ostream& operator<<(std::ostream& os, const Complex& z);
};

#endif
