#include <iostream>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Shape draw" << std::endl;
    }
};


class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Circle draw" << std::endl;
    }
};

void printShape(const Shape& shape) {
    shape.draw();
}

int main() {
    Circle myCircle;

    printShape(myCircle);

    return 0;
}