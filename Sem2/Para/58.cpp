#include <iostream>
#include <string>

template <typename T>
int countIf(T arr[], int size, T value) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int main() {
    int arrInt[] = { 1, 3, 3, 7, 3, 2 };
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
    int valueInt = 3;

    std::cout << "Count of " << valueInt << ": "
              << countIf(arrInt, sizeInt, valueInt) << std::endl;

    char arrChar[] = { 'a', 'b', 'a', 'c' };
    int sizeChar = sizeof(arrChar) / sizeof(arrChar[0]);
    char valueChar = 'a';

    std::cout << "Count of '" << valueChar << "': "
              << countIf(arrChar, sizeChar, valueChar) << std::endl;

    std::string arrStr[] = { "apple", "banana", "apple", "orange", "apple" };
    int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);
    std::string valueStr = "apple";

    std::cout << "Count of \"" << valueStr << "\": "
              << countIf(arrStr, sizeStr, valueStr) << std::endl;

    return 0;
}