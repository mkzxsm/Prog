#include <iostream>

template <typename T>
bool isSorted(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
int linearSearch(T arr[], int size, T target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::boolalpha(std::cout);

    int a[] = { 1, 3, 5, 7, 9 };
    int b[] = { 4, 2, 6, 1 };
    int sizeA = sizeof(a) / sizeof(a[0]);
    int sizeB = sizeof(b) / sizeof(b[0]);

    std::cout << "a is sorted: " << isSorted(a, sizeA) << std::endl;
    std::cout << "b is sorted: " << isSorted(b, sizeB) << std::endl;
    std::cout << "Search 5 in a: index = " << linearSearch(a, sizeA, 5) << std::endl;
    std::cout << "Search 8 in a: index = " << linearSearch(a, sizeA, 8) << std::endl;

    double c[] = { 1.2, 3.4, 5.6, 7.8 };
    double d[] = { 9.1, 2.2, 4.5 };
    int sizeC = sizeof(c) / sizeof(c[0]);
    int sizeD = sizeof(d) / sizeof(d[0]);

    std::cout << "c is sorted: " << isSorted(c, sizeC) << std::endl;
    std::cout << "d is sorted: " << isSorted(d, sizeD) << std::endl;
    std::cout << "Search 5.6 in c: index = " << linearSearch(c, sizeC, 5.6) << std::endl;
    std::cout << "Search 1.1 in c: index = " << linearSearch(c, sizeC, 1.1) << std::endl;

    return 0;
}