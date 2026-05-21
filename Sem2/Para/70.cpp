#include <iostream>
#include <stdexcept>

using namespace std;

class Vector {
private:
    int size;
    int* data;

public:
    Vector(int s) try : size(s), data(nullptr) {
        if (s <= 0) {
            throw invalid_argument("Invalid size");
        }
        data = new int[s];
        cout << "Vector created: size = " << size << endl;

    } catch (const invalid_argument& e) {
        cout << "Error in constructor: " << e.what() << endl;

        throw;
    }

    ~Vector() {
        delete[] data;
    }
};

int main() {
    try {
        Vector v_bad(-3);
    } catch (const invalid_argument& e) {
    }

    try {
        Vector v_good(5);
    } catch (const invalid_argument& e) {
        cout << "Main caught: " << e.what() << endl;
    }

    return 0;
}