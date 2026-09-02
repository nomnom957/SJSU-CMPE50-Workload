//============================================================================
// Name        : CMPE50-Lab-9.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "../polynomial.h"
using namespace std;

Polynomial::Polynomial()
{
    degree = 10;
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = 0;
    }
}

Polynomial::Polynomial(int degr)
{
    degree = degr;
    if (degree < 0) degree = 0;
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &poly)
{
    degree = poly.get_degree();
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = poly.get_coeff(i);
    }
}

Polynomial::Polynomial(double cf[], int deg)
{
    degree = deg;
    if (degree < 0) degree = 0;
    coeff = new double[degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = cf[i];
    }
}

Polynomial::Polynomial(double ct)
{
    degree = 0;
    coeff = new double[1];
    coeff[0] = ct;
}

Polynomial::~Polynomial()
{
    delete [] coeff;
}

int Polynomial::get_degree() const
{
    return degree;
}

double Polynomial::get_coeff(int deg) const
{
    if (deg < 0 || degree < deg)
    {
        return 0;
    }
    return coeff[deg];
}

void Polynomial::set_coeff(int degr, double val)
{
    if (degr < 0 || degree < degr)
    {
        cout << "Degree exceeded." << endl;
        return;
    }
    coeff[degr] = val;
}

double Polynomial::evaluate(double val)
{
    double acc = 0.0;
    for (int i = degree; i >= 0; --i)
    {
        acc = acc * val + coeff[i];
    }
    return acc;
}

void Polynomial::operator =(const Polynomial &poly)
{
    if (this == &poly)
    {
        return;
    }
    int newdeg = poly.get_degree();
    double* newcoeff = new double[newdeg + 1];
    for (int i = 0; i <= newdeg; ++i)
    {
        newcoeff[i] = poly.get_coeff(i);
    }
    delete [] coeff;
    coeff = newcoeff;
    degree = newdeg;
}

Polynomial operator+(const Polynomial &pola, const Polynomial &polb)
{
    int da = pola.get_degree();
    int db = polb.get_degree();
    int md = (da > db ? da : db);
    Polynomial res(md);
    for (int i = 0; i <= md; ++i)
    {
        res.set_coeff(i, pola.get_coeff(i) + polb.get_coeff(i));
    }
    return res;
}

Polynomial operator-(const Polynomial &pola, const Polynomial &polb)
{
    int da = pola.get_degree();
    int db = polb.get_degree();
    int md = (da > db ? da : db);
    Polynomial res(md);
    for (int i = 0; i <= md; ++i)
    {
        res.set_coeff(i, pola.get_coeff(i) - polb.get_coeff(i));
    }
    return res;
}

Polynomial operator*(const Polynomial &pola, const Polynomial &polb)
{
    int da = pola.get_degree();
    int db = polb.get_degree();
    int pd = da + db;
    Polynomial res(pd);
    for (int i = 0; i <= pd; ++i) res.set_coeff(i, 0.0);
    for (int i = 0; i <= da; ++i)
    {
        double ai = pola.get_coeff(i);
        if (ai == 0.0) continue;
        for (int j = 0; j <= db; ++j)
        {
            double val = res.get_coeff(i + j) + ai * polb.get_coeff(j);
            res.set_coeff(i + j, val);
        }
    }
    return res;
}

ostream& operator << (ostream& ost, const Polynomial &pol)
{
    int deg = pol.get_degree();
    bool first = true;
    bool allZero = true;
    for (int i = 0; i <= deg; ++i)
    {
        if (pol.get_coeff(i) != 0.0) { allZero = false; break; }
    }
    if (allZero) { ost << 0; return ost; }

    for (int i = deg; i >= 0; --i)
    {
        double c = pol.get_coeff(i);
        if (c == 0.0) continue;

        if (!first)
        {
            ost << (c >= 0.0 ? " + " : " - ");
        }
        else
        {
            if (c < 0.0) ost << "-";
            first = false;
        }

        double a = std::fabs(c);
        if (i == 0)
        {
            ost << a;
        }
        else if (i == 1)
        {
            if (a != 1.0) ost << a;
            ost << "x";
        }
        else
        {
            if (a != 1.0) ost << a;
            ost << "x^" << i;
        }
    }
    return ost;
}

int main() {
    double fcoef[] = {0, -3, 5, 2};
    double gcoef[] = {7, 0, -10};

    Polynomial f(fcoef, 3);
    Polynomial g(gcoef, 2);

    cout << "f(x) = " << f << endl;
    cout << "g(x) = " << g << endl;
    cout << "f + g = " << f + g << endl;
    cout << "f - g = " << f - g << endl;
    cout << "f * g = " << f * g << endl;

    double x = 2.0;
    cout << "f(" << x << ") = " << f.evaluate(x) << endl;

    return 0;
}

/*
 * f(x) = 2x^3 + 5x^2 - 3x
 * g(x) = -10x^2 + 7
 * f + g = 2x^3 - 5x^2 - 3x + 7
 *f - g = 2x^3 + 15x^2 - 3x - 7
 *f f * g = -20x^5 - 50x^4 + 44x^3 + 35x^2 - 21x
 *f f(2) = 30
 */
