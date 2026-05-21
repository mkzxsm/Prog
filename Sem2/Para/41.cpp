#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal constructor" << endl;
    }

    ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() {
        cout << "Dog constructor" << endl;
    }

    ~Dog() {
        cout << "Dog destructor" << endl;
    }
};

int main() {
    Dog dog;
    return 0;
}