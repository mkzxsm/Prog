#include <iostream>
#include <string>

using namespace std;

void readAge(int age) noexcept(false) {
    if (age < 0) {
        throw string("Age cannot be negative");
    }
    cout << "Age is valid: " << age << endl;
}


void printAge(int age) noexcept {
    cout << "Printing age safely: " << age << endl;
}

int main() {
    try {
        readAge(20);
    } catch (const string& error_msg) {
        cout << "Error: " << error_msg << endl;
    }

    try {
        readAge(-10);
    } catch (const string& error_msg) {
        cout << "Error: " << error_msg << endl;
    }

    printAge(20);

    return 0;
}