#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    string name;
    Date birthDate;
};

int main() {
    Person p;
    cin >> p.name >> p.birthDate.day >> p.birthDate.month >> p.birthDate.year;
    cout << p.name << " — " << p.birthDate.day << "." << p.birthDate.month << "." << p.birthDate.year << endl;
}