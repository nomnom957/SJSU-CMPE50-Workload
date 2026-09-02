#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
    void erase() { std::cout << "Figure::erase()\n"; }
    void draw()  { std::cout << "Figure::draw()\n"; }
    void center() {
        std::cout << "Figure::center() -> calling erase() then draw()\n";
        erase();
        draw();
    }
    virtual ~Figure() = default;
};

#endif
