#include <iostream>
using namespace std;

class Base
{
protected:
    int a;
};
class Derived : public Base
{
    void set_a(int x)
    {
        a = x;
    }
    int get_a() const
    {
        return a;
    }
};

int main()
{
    Derived d;
    d.set_a(5);
    cout << d.get_a() << endl;
}