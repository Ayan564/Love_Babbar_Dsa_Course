#include <iostream>

using namespace std;

class Shape // final
{
public:
    virtual void draw() // final
    {
        cout << "Generic drawing..." << endl;
    }
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Circle drawing..." << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Rectangle drawing..." << endl;
    }
};

class Triangle : public Shape
{
public:
    void draw() override
    {
        cout << "Triangle drawing..." << endl;
    }
};

void ShapeDrawing(Shape *s)
{
    s->draw(); // draw is polymorphic
}

int main()
{
    // Circle c;
    // Rectangle r;
    // Triangle *t = new Triangle();
    // ShapeDrawing(&c);
    // ShapeDrawing(&r);
    // ShapeDrawing(t);

    // virtual keyword
    Shape *s = new Shape();
    s->draw();

    // UPCASTING
    Shape *s3 = new Circle();
    s3->draw();
    Circle *c = new Circle();
    c->draw();

    // DOWNCASTING
    Shape *s2 = new Shape();
    Circle *c2 = (Circle *)s2; 
    c2->draw();
    return 0;
}
