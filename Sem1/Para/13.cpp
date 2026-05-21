#include <iostream>
using namespace std;
int getNumber()
{
    int number;
    cout << "Введи число";
    cin >> number;
    return number;
}
int main ()
{
    int num = getNumber();
    cout << "number=" << num;
    return 0;
}
