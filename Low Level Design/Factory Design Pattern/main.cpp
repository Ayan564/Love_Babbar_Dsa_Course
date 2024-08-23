#include "shapeFactory.h"

int main() {
    // Create an instance of the shape factory
    ShapeFactory shapeFactory;

    // Call the createShape method to create a shape
    Shape* shape = shapeFactory.getShape("circle");

    // Use the shape object
    shape->draw();

    // Clean up the memory
    delete shape;

    return 0;
}