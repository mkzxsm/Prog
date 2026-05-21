#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
};

int main()
{
    string tempname;
    int tempage;
    getline(cin, tempname);
    cin >> tempage;
    cin.ignore();
    Student s1 = {tempname, tempage};
    getline(cin, tempname);
    cin >> tempage;
    Student s2;
    s2.name = tempname;
    s2.age = tempage;
    cout << s1.name << " " << s1.age << endl;
    cout << s2.name << " " << s2.age << endl;
}
