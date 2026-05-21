#include <iostream>
#include <string>

template <typename T>
class Box {
private:
    T value;

public:
    Box(T val) : value(val) {}

    T get() const {
        return value;
    }

    void set(T val) {
        value = val;
    }

    void print() const {
        std::cout << value;
    }

    bool operator==(const Box<T>& other) const {
        return this->value == other.value;
    }
};

int main() {
    std::boolalpha(std::cout);

    Box<int> a(5), b(5), c(10);

    std::cout << "a = " << a.get() << ", b = " << b.get() << ", c = " << c.get() << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;

    Box<double> x(3.14), y(3.14), z(2.71);

    std::cout << "x = " << x.get() << ", y = " << y.get() << ", z = " << z.get() << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x == z: " << (x == z) << std::endl;

    Box<std::string> str1("hello"), str2("hello"), str3("world");

    std::cout << "str1 = "; str1.print();
    std::cout << ", str2 = "; str2.print();
    std::cout << ", str3 = "; str3.print(); std::cout << std::endl;

    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 == str3: " << (str1 == str3) << std::endl;

    return 0;
}