#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
public:
    void erase() { std::cout << "Triangle::erase()\n"; }
    void draw()  { std::cout << "Triangle::draw()\n"; }
    void center() {
        std::cout << "Triangle::center() -> calling erase() then draw()\n";
        erase();
        draw();
    }
};

#endif
