#include <iostream>

class Shape
{
public:
    virtual void area() const = 0;
};

class Rectangle : public Shape
{
    void area() const override
    {
        std::cout << "Rectangle area";
    }
};

int main()
{
    Shape* shape = new Rectangle();
    shape->area();

    delete shape;
}