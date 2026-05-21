#include <iostream>
#include <string>

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a_int = 5, b_int = 10;
    mySwap(a_int, b_int);
    std::cout << "After swap: a = " << a_int << ", b = " << b_int << std::endl;

    double a_double = 3.14, b_double = 2.71;
    mySwap(a_double, b_double);
    std::cout << "After swap: a = " << a_double << ", b = " << b_double << std::endl;

    std::string a_str = "hello", b_str = "world";
    mySwap(a_str, b_str);
    std::cout << "After swap: a = " << a_str << ", b = " << b_str << std::endl;

    return 0;
}