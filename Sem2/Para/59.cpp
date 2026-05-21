#include <iostream>

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int arrInt[] = { 1, 2, 3, 4, 5 };
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);

    std::cout << "Original: ";
    printArray(arrInt, sizeInt);

    reverseArray(arrInt, sizeInt);

    std::cout << "Reversed: ";
    printArray(arrInt, sizeInt);
    std::cout << std::endl;

    double arrDouble[] = { 1.1, 2.2, 3.3, 4.4 };
    int sizeDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);

    std::cout << "Original: ";
    printArray(arrDouble, sizeDouble);

    reverseArray(arrDouble, sizeDouble);

    std::cout << "Reversed: ";
    printArray(arrDouble, sizeDouble);
    std::cout << std::endl;

    char arrChar[] = { 'a', 'b', 'c', 'd' };
    int sizeChar = sizeof(arrChar) / sizeof(arrChar[0]);

    std::cout << "Original: ";
    printArray(arrChar, sizeChar);

    reverseArray(arrChar, sizeChar);

    std::cout << "Reversed: ";
    printArray(arrChar, sizeChar);

    return 0;
}