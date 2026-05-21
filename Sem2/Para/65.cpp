#include <iostream>

using namespace std;
int getElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw index;
    }
    return arr[index];
}

void printElement(int arr[], int size, int index) {
    int value = getElement(arr, size, index);
    cout << "arr[" << index << "] = " << value << endl;
}

int main() {
    int arr[] = {10, 20, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    try {
        printElement(arr, size, 1);
        cout << "Stack unwinding..." << endl;
        printElement(arr, size, 10);
        cout << "This line will be skipped." << endl;

    } catch (int bad_index) {
        cout << "Error: invalid index = " << bad_index << endl;
    }

    return 0;
}