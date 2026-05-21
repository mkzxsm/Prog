#include <iostream>
#include <string>

using namespace std;

double divide(double a, double b) {
    if (b == 0.0) {
        throw string("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        double result1 = divide(10.0, 2.0);
        cout << "10 / 2 = " << result1 << endl;
        double result2 = divide(5.0, 0.0);
        cout << "5 / 0 = " << result2 << endl;

    } catch (const string& error_message) {
        cout << "Error: " << error_message << endl;
    }

    return 0;
}