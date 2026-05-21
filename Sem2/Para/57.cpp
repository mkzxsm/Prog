#include <iostream>

template <typename T>
void bubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arrInt[] = { 5, 3, 8, 1, 2 };
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
    for (int i = 0; i < sizeInt; i++)
    {
        std::cout << arrInt[i] << " ";
    }
    std::cout << std::endl;
    bubbleSort(arrInt, sizeInt);
    for (int i = 0; i < sizeInt; i++)
    {
        std::cout << arrInt[i] << " ";
    }
    std::cout << std::endl;
    char arrChar[] = { 'z', 'a', 'm', 'b' };
    int sizeChar = sizeof(arrChar) / sizeof(arrChar[0]);
    for (int i = 0; i < sizeChar; i++)
    {
        std::cout << arrChar[i] << " ";
    }
    std::cout << std::endl;
    bubbleSort(arrChar, sizeChar);
    for (int i = 0; i < sizeChar; i++)
    {
        std::cout << arrChar[i] << " ";
    }
}
