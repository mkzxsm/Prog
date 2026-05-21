#include <iostream>
#include <string>

using namespace std;

class FileException {
public:
    string message;

    FileException(const string& msg) : message(msg) {}
};

void processFile(const string& filename) {
    if (filename.empty()) {
        throw FileException("File not found");
    }
    cout << "Processing file: " << filename << endl;
}

int main() {
    try {

        try {
            processFile("");
        } catch (const FileException& e) {
            cout << "Inner catch: " << e.message << endl;

            throw;
        }

    } catch (const FileException& e) {
        cout << "Rethrown and caught at top level: " << e.message << endl;
    }

    return 0;
}