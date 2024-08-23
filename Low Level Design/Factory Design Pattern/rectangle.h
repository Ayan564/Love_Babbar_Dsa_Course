#if !defined(RECTANGLE_H)
#define RECTANGLE_H

#include <iostream>
#include"shape.h"

// Concrete class for Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Draw rectangle ..." << std::endl;
    }
};

#endif // RECTANGLE_H)

