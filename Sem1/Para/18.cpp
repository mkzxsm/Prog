#include <iostream>
using namespace std;
int counter = 0;
int main()
{
    int counter = 10;
    cout << "global=" << ::counter << endl;
    cout << "local=" << counter << endl;
}