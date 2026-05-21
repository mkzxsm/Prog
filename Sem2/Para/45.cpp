#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog barks" << std::endl;
    }
};

int main() {
    Animal* myAnimal = new Dog();
    Animal* animal = new Animal();
    myAnimal->speak();
    animal->speak();
    delete animal;
    delete myAnimal;

    return 0;
}
