#include <iostream>

class Base
{
public:
    void Show()
    {
        std::cout << "Base show";
    }
};
class Derived : public Base
{
public:
    void Show()
    {
        std::cout << "Derived show";
    }
};

int main()
{
    Base* base = new Base();
    base->Show();
    delete base;
}