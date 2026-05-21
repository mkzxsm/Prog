#include <iostream>
using namespace std;

class Base {
public:
    void baseMethod() {
        cout << "Base public method" << endl;
    }
};

class Derived : private Base {
public:
    void derivedMethod() {
        cout << "Derived method" << endl;
        baseMethod();
    }
};

int main()
{
    Derived derived;
    derived.derivedMethod();
}