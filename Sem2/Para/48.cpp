#include <iostream>

class Base
{
public:
    virtual void info() const
    {
        std::cout << "Base info";
    }
};
class Derived : public Base
{
public:
    void info() const override
    {
        std::cout << "Derived info";
    }
};

int main()
{
    Derived derived;
    derived.info();
}