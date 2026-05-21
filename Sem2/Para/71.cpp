#include <iostream>
#include <stdexcept>

using namespace std;

void checkIndex() {
    throw out_of_range("index out of range");
}

void checkArg() {
    throw invalid_argument("argument must be positive");
}

void checkRuntime() {
    throw runtime_error("unexpected error occurred");
}

int main() {

    try {
        checkIndex();
    } catch (const out_of_range& e) {
        cout << "out_of_range: " << e.what() << endl;
    }

    try {
        checkArg();
    } catch (const invalid_argument& e) {
        cout << "invalid_argument: " << e.what() << endl;
    }

    try {
        checkRuntime();
    } catch (const runtime_error& e) {
        cout << "runtime_error: " << e.what() << endl;
    }


    try {
        checkIndex();
    } catch (const exception& e) {
        cout << "Via base — out_of_range: " << e.what() << endl;
    }

    try {
        checkArg();
    } catch (const exception& e) {
        cout << "Via base — invalid_argument: " << e.what() << endl;
    }

    try {
        checkRuntime();
    } catch (const exception& e) {
        cout << "Via base — runtime_error: " << e.what() << endl;
    }

    return 0;
}