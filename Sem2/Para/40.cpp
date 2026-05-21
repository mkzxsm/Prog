#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string type;
public:
    Animal(string t) : type(t) {}

    void eat() {
        cout << type << " eats" << endl;
    }

    void sleep() {
        cout << type << " sleeps" << endl;
    }

    void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("Dog") {}

    void speak() {
        cout << type << " barks" << endl;
    }
};

class Cat : public Animal {
public:
    Cat() : Animal("Cat") {}

    void speak() {
        cout << type << " meows" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();
    dog.sleep();
    dog.speak();

    cout << endl;

    Cat cat;
    cat.eat();
    cat.sleep();
    cat.speak();

    return 0;
}