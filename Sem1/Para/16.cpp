#include <iostream>
using namespace std;

int power(int a, int b)
{
    int res = 1;
    for (int i = 0; i < b; ++i)
    {
        res = res * a;
    }
    return res;
}

int main()
{
    int num1, num2;
    cout << "Введи число";
    cin >> num1 >> num2;
    cout << power(num1, num2);
    return 0;
}
