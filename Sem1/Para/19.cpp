#include <iostream>
using namespace std;

void showLocal()
{
    int x = 5;
    cout << "x=" << x << endl;
}

int main()
{
    showLocal();
    showLocal();
    return 0;
}
