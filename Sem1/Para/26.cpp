#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

void printPoint(Point p)
{
    cout << "(" << p.x << "," << p.y << ")" << endl;
};

int main()
{
    Point myPoint;
    cin >> myPoint.x >> myPoint.y;
    printPoint(myPoint);
}
