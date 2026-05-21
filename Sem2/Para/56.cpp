#include <iostream>

template <typename T>
T findMin(T arr[], int size) {
    T minElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return minElement;
}

template <typename T>
T findMax(T arr[], int size) {
    T maxElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    int arrInt[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);

    std::cout << "Min = " << findMin(arrInt, sizeInt)
              << ", Max = " << findMax(arrInt, sizeInt) << std::endl;

    double arrDouble[] = { 3.5, 2.1, 8.8, 1.0 };
    int sizeDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);

    std::cout << "Min = " << findMin(arrDouble, sizeDouble)
              << ", Max = " << findMax(arrDouble, sizeDouble) << std::endl;

    return 0;
}