#include <iostream>

template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T a, T b) : first(a), second(b) {}

    T getFirst() const { return first; }
    T getSecond() const { return second; }

    T sum() const { return first + second; }

    void print() const {
        std::cout << "Pair: (" << first << ", " << second << "), Sum = " << sum() << std::endl;
    }
};

int main() {
    Pair<int> p(10, 20);
    p.print();

    Pair<double> p2(1.5, 2.5);
    p2.print();

    return 0;
}