//============================================================================
// Name        : CMPE50-Lab-10.2.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "figure.h"
#include "circle.h"
#include "triangle.h"
using namespace std;

void myDraw(Figure *fig)
{
    fig->draw();
    cout << "\nmyDraw: Derived class object calling center().\n";
    fig->center();
}

int main()
{
    Figure *fig;
    Triangle *tri = new Triangle;
    fig = tri;
    fig->draw();
    cout << "\nDerived class Triangle object calling center().\n";
    fig->center();
    myDraw(tri);

    Circle *cir = new Circle;
    fig = cir;
    fig->draw();
    cout << "\nDerived class Circle object calling center().\n";
    fig->center();
    myDraw(cir);

    return 0;
}

/*
Figure::draw()

Derived class Triangle object calling center().
Figure::center() -> calling erase() then draw()
Figure::erase()
Figure::draw()
Figure::draw()

myDraw: Derived class object calling center().
Figure::center() -> calling erase() then draw()
Figure::erase()
Figure::draw()
Figure::draw()

Derived class Circle object calling center().
Figure::center() -> calling erase() then draw()
Figure::erase()
Figure::draw()
Figure::draw()

myDraw: Derived class object calling center().
Figure::center() -> calling erase() then draw()
Figure::erase()
Figure::draw()
 */
