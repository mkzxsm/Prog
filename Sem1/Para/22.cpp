#include <iostream>
using namespace std;

struct Point
{
    int x = 0;
    int y = 0;
};

int main()
{
    Point p;
    cin >> p.x >> p.y;

    cout << "x=" << p.x << " y=" << p.y << endl;

    return 0;
}
