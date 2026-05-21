#include <iostream>
using namespace std;
class Base {
public:
    Base() {
        cout << "Base" << endl;
    }
    ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived" << endl;
    }
    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Derived obj;

    return 0;
}