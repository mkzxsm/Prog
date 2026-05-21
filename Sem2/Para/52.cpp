#include <iostream>

class Base
{
public:
    virtual void show()
    {
        std::cout << "Base info" << std::endl;
    }
    Base(){show();}
};

class Arrived : public Base
{
public:
    void show() override
    {
        std::cout << "Arrived info" << std::endl;
    }
    Arrived(){show();}
};

int main()
{
    Base* b = new Arrived;
    delete b;
}