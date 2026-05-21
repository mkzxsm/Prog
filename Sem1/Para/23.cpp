#include <iostream>
using namespace std;
struct Square
{
    int a = 0;
    int b = 0;

    int getSquare()
    {
        return a*b;
    }
};
int main()
{
    Square square;
    cout << "Введи довжити і ширину" << endl;
    cin >> square.a >> square.b;
    cout << "Square=" << square.getSquare() << endl;
}