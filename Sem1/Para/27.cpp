#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

void movePoint(Point& p)
{
    p.x++;
    p.y++;
}

int main()
{
    Point myPoint;

    cin >> myPoint.x >> myPoint.y;

    movePoint(myPoint);

    cout << "(" << myPoint.x << "," << myPoint.y << ")" << endl;

    return 0;
}
