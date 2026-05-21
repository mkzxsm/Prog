#include <iostream>
using namespace std;
bool isEven(int x)
{
    return x%2 == 0;
}
int main()
{
    int num;
    cout << "Введи число";
    cin >> num;
    cout << boolalpha << isEven(num);
    return 0;
}