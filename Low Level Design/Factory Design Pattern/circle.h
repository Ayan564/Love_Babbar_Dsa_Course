#if !defined(RECTANGLE_H)
#define RECTANGLE_H

#include <iostream>
#include"shape.h"

// Concrete class for Rectangle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Draw circle ..." << std::endl;
    }
};

#endif // RECTANGLE_H)

