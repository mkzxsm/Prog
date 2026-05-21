#include <iostream>
#include <iomanip>
using namespace std;

void print(int n)
{
    cout << n << endl;
}

void print(double x)
{
    cout << fixed << setprecision(2) << x << endl;
}

int main()
{
    print(5);
    print(3.14);
    return 0;
}
