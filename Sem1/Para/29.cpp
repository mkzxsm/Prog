#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p;
    Point* ptr = &p;
    cin >> ptr->x >> ptr->y;
    cout << "x=" << ptr->x << " y=" << ptr->y << endl;
}