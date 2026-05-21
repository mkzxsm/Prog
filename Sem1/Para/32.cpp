#include <iostream>
#include <string>
using namespace std;
struct PointStruct {
    int x;
    int y;
    string label = "Struct Point";
};

class PointClass {
    int x;
    int y;
    string label = "Class Point";

public:
    void displayInfo() const {
        cout << label << ": x=" << x << ", y=" << y << endl;
    }

    void initialize(int valX, int valY) {
        x = valX;
        y = valY;
    }
};

int main() {

    PointStruct s;

    s.x = 10;
    s.y = 20;

    cout << "Accessing Struct Fields:" << endl;
    cout << s.label << ": x=" << s.x << ", y=" << s.y << endl;

    cout << "--------------------------------------" << endl;

    PointClass c;
    c.initialize(30, 40);

    cout << "Accessing Class Fields:" << endl;
    c.displayInfo();

    return 0;
}