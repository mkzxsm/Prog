#include <iostream>
using namespace std;
int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int num1, num2;
    cout << "Enter a numbers";
    cin >> num1 >> num2;
    cout << sum(num1, num2);
    return 0;
}
