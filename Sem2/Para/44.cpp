#include <iostream>

class Printer {
public:
    void print(int value) {
        std::cout << "Print int" << std::endl;
    }

    void print(double value) {
        std::cout << "Print double" << std::endl;
    }
};

int main() {
    Printer printer;

    printer.print(10);

    printer.print(3.14);

    return 0;
}