#include <iostream>
using namespace std;

class Base {
public:
    void baseMethod() {
        cout << "Base public method" << endl;
    }
};

class Derived : public Base {
public:
    void derivedMethod() {
        cout << "Derived method" << endl;
    }
};

int main() {
    Derived obj;

    obj.derivedMethod();
    obj.baseMethod();

    return 0;
}