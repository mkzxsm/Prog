#include <iostream>
#include <string>

using namespace std;

class AppException {
public:
    string message;
    AppException(const string& msg) : message(msg) {}
};

class FileException : public AppException {
public:
    FileException(const string& msg) : AppException(msg) {}
};

class NetworkException : public AppException {
public:
    NetworkException(const string& msg) : AppException(msg) {}
};

int main() {
    try {
        throw FileException("File not found");
    } catch (const FileException& e) {
        cout << "Caught FileException: " << e.message << endl;
    }

    try {
        throw NetworkException("Connection refused");
    } catch (const NetworkException& e) {
        cout << "Caught NetworkException: " << e.message << endl;
    }

    try {
        throw FileException("File not found");
    } catch (const AppException& e) {
        cout << "Caught via base: " << e.message << endl;
    }

    try {
        throw NetworkException("Connection refused");
    } catch (const AppException& e) {
        cout << "Caught via base: " << e.message << endl;
    }

    return 0;
}