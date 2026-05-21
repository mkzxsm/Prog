#include  <iostream>
using namespace std;

class Animal
{
public:
    void Speak(){
        cout << "Animal sound" << endl;
    };
};

class Dog: public Animal
{
public:
    void Speak()
    {
        cout << "Dog barks" << endl;
    }
};

int main()
{
    Animal a;
    a.Speak();
    Dog b;
    b.Speak();
}