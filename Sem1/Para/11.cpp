#include <iostream>
using namespace std;
int square(int x) { return x * x; }

int main()
{
    int numb;
    cout << "Enter a number: ";
    cin >> numb;
    cout << square(numb);
    return 0;
}
