#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int num1, num2;
    cout << "Введи числа";
    cin >> num1 >> num2;
    cout << max(num1,num2);
    return 0;
}
