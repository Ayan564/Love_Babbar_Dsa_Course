#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <string>
#include "circle.h"
#include "rectangle.h"

class ShapeFactory {
public:
    Shape* getShape(const std::string& input) {
        if (input == "CIRCLE") {
            return new Circle(); // Create a new instance of the 'Circle' class
        } else if (input == "RECTANGLE") {
            return new Rectangle(); // Create a new instance of the 'Rectangle' class
        }
        return nullptr;
    }
};

#endif // SHAPE_FACTORY_H
