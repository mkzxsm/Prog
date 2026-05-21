#include <iostream>
using namespace std;

class A
{
    public:
    A ()
    {
        cout<<"Constructor A"<<endl;
    }
};
class B: public A
{
    public:
    B ()
    {
        cout<<"Constructor B"<<endl;
    }
};
class C: public B
{
    public:
    C ()
    {
        cout<<"Constructor C"<<endl;
    }
};

int main()
{
    C c;
}