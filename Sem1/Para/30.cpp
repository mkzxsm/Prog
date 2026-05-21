#include <iostream>
using namespace std;
class Point2D {
public:

    int x;
    int y;

    Point2D() : x(0), y(0) {}

    Point2D(int initialX, int initialY) : x(initialX), y(initialY) {}
};

int main() {
    int inputX, inputY;
    cin >> inputX >> inputY;

    Point2D p(inputX, inputY);
    cout << "x=" << p.x << " y=" << p.y << endl;

    return 0;
}