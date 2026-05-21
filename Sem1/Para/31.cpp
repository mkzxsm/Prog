#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    string name;
    int age;

    Student(const string& n, int a) : name(n), age(a) {}

    void displayInfo() const {
        cout << name << " " << age << endl;
    }
};

int main() {
    string name1;
    int age1;

    cin >> name1 >> age1;

    string name2;
    int age2;

    cin >> name2 >> age2;

    Student student1(name1, age1);
    Student student2(name2, age2);

    student1.displayInfo();

    student2.displayInfo();

    return 0;
}