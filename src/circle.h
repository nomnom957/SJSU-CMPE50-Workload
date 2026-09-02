#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
public:
    void erase() { std::cout << "Circle::erase()\n"; }
    void draw()  { std::cout << "Circle::draw()\n"; }
    void center() {
        std::cout << "Circle::center() -> calling erase() then draw()\n";
        erase();
        draw();
    }
};

#endif
