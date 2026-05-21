#include <iostream>
#include <stdexcept>

using namespace std;

class SafeArray {
private:
    int* data;
    int size;

public:
    SafeArray(int s) : size(s) {
        data = new int[s];
        for (int i = 0; i < s; ++i) {
            data[i] = (i + 1) * 10;
        }
    }

    ~SafeArray() {
        delete[] data;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("index out of range");
        }
        return data[index];
    }
};

class Logger {
public:
    Logger() {
    }

    ~Logger() {
        cout << "Logger destroyed" << endl;
    }
};

int main() {
    try {
        Logger log;
        SafeArray arr(3);
        cout << "arr[1] = " << arr[1] << endl;
        arr[10] = 50;
        cout << "This will not be printed." << endl;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}