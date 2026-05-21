#include <iostream>
using namespace std;
int total = 0;
void add(int x)
{
    total+=x;
}
int main()
{
    add(5);
    cout << total << endl;
    add(6);
    cout << total << endl;
    add(10);
    cout << total << endl;
}