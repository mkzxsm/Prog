#include <iostream>

using namespace std;

class EncapsulatedValue {
private:
    int value;

public:
    void setValue(int newValue) {
        value = newValue;
    }

    int getValue() const {
        return value;
    }

    void displayValue() const {
        cout << "value=" << value << endl;
    }
};

int main() {
    int inputVal;

    cin >> inputVal;

    EncapsulatedValue obj;

    obj.setValue(inputVal);


    obj.displayValue();

    return 0;
}